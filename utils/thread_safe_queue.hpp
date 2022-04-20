#ifndef THREAD_SAFE_QUEUE_HPP
#define THREAD_SAFE_QUEUE_HPP

#include <atomic>
#include <thread>
#include <mutex>
#include <condition_variable>

#include <stdexcept>
#include <iostream>
#include <list>
#include <vector>
#include <queue>

#include <unistd.h>


enum QResult {
    OK, CLOSED
};

template <typename T>
class ThreadSafeQueue {
private:
    enum class State {
        OPEN, CLOSED
    };

    // The current state.
    State _state;
    // The current size.
    size_t _current_size;
    // The maximal size.
    size_t _max_size;
    // The condition variables to use for pushing/popping.
    std::condition_variable _cv_push, _cv_pop;
    // The mutex for locking the queue.
    mutable std::mutex _mutex;
    // The list that the queue is implemented with.
    std::list<T> _list;
    // How many producers are using it
    int _n_producer;
    int _n_closed_producer;

public:
    // Initialize the queue with a maximal size.
    explicit ThreadSafeQueue(int n_producer, size_t max_size = 0): \
        _state(State::OPEN), _current_size(0), _n_producer(n_producer), _n_closed_producer(0), _max_size(max_size) {}

    ~ThreadSafeQueue() = default;

    // 禁止拷贝
    ThreadSafeQueue& operator=(const ThreadSafeQueue&) = delete;

    // 压入元素
    void push(T const& v) {
        decltype(_list) temp_list;
        temp_list.push_back(v);

        {
            std::unique_lock<std::mutex> lock(_mutex);

            // 等待队列有空位
            while (_current_size == _max_size && _state == State::OPEN) {
                _cv_push.wait(lock) ;
            }

            if (_state == State::CLOSED) {
                throw std::runtime_error("Trying to push to a closed queue.");
            }

            // 压入队列
            _current_size += 1;
            _list.splice(_list.end(), temp_list, temp_list.begin());

            // 唤醒取数据的线程
            _cv_pop.notify_one();
        }
    }

    // 压入元素（右值引用）
    void push(T && v) {
        decltype(_list) temp_list;
        temp_list.push_back(v);

        {
            std::unique_lock<std::mutex> lock(_mutex);

            // 等待队列有空位
            while (_current_size == _max_size && _state == State::OPEN) {
                _cv_push.wait(lock) ;
            }

            if (_state == State::CLOSED) {
                throw std::runtime_error("Trying to push to a closed queue.");
            }

            // 压入队列
            _current_size += 1;
            _list.splice(_list.end(), temp_list, temp_list.begin());

            // 唤醒取数据的线程
            _cv_pop.notify_one();
        }
    }

    // 取出元素
    QResult pop(T& v) {
        decltype(_list) temp_list;

        {
            std::unique_lock<std::mutex> lock(_mutex);

            // 等待队列中存在数据
            while (_list.empty() && _state != State::CLOSED) {
                _cv_pop.wait(lock);
            }

            // 若队列已关闭且为空，则没有值可取，返回CLOSED
            if (_list.empty() && _state == State::CLOSED) {
                return CLOSED;
            }

            // 取出数据
            _current_size -= 1;
            temp_list.splice(temp_list.begin(), _list, std::prev(_list.end()));

            // 清空队列
            _current_size = 0;
            _list.clear();

            // 唤醒压入线程
            _cv_push.notify_one();
        }

        // 将取出的数据写入 v
        v = temp_list.front();

        return OK;
    }

    // 关闭队列
    void close() noexcept {
        std::unique_lock<std::mutex> lock(_mutex);
        // 当且仅当所有使用该队列的producer都关闭时，关闭该队列
        // 应保证任一producer仅且仅能调用close方法一次
        if (++_n_closed_producer == _n_producer) {
            _state = State::CLOSED;
        }

        _cv_pop.notify_all();
        _cv_push.notify_all();
    }
};

#endif //THREAD_SAFE_QUEUE_HPP
