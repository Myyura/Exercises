//
// Created by Myyura on 2022/04/20.
//

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
    // The queue
    std::queue<T> _queue;
    // Mode, 0: drop, 1: wait when queue is full
    int _mode;

public:
    // Initialize the queue with a maximal size.
    explicit ThreadSafeQueue(size_t max_size = 1, int mode = 0): \
        _state(State::OPEN), _current_size(0), _max_size(max_size), _mode(mode) 
    {
        if (max_size <= 0) {
            throw std::invalid_argument("max_size must be greater than 0.");
        }
    }

    ~ThreadSafeQueue() = default;

    // 禁止拷贝
    ThreadSafeQueue& operator=(const ThreadSafeQueue&) = delete;

    bool full(void) { return _max_size >= _current_size; }
    bool empty(void) { return _current_size <= 0; }

    // 压入元素
    void push(T const& v) {
        std::unique_lock<std::mutex> lock(_mutex);
        if (full()) {
            if (_mode == 0) {
                // drop mode, 直接pop掉一个元素
                _queue.pop();
                _current_size--;
            } else if (_mode == 1) {
                // wait mode, 等待队列有空位又或者队列在其他地方被关闭
                _cv_push.wait(lock, [&]{ return !full() || _state != State::OPEN; });
            }
        }

        if (_state == State::CLOSED) {
            // throw std::runtime_error("Trying to push to a closed queue.");
            return;
        }

        _current_size++;
        _queue.push(v);

        _cv_pop.notify_one();
    }

    // 压入元素
    void push(T && v) {
        std::unique_lock<std::mutex> lock(_mutex);
        if (full()) {
            if (_mode == 0) {
                // drop mode, 直接pop掉一个元素
                _queue.pop();
                _current_size--;
            } else if (_mode == 1) {
                // wait mode, 等待队列有空位又或者队列在其他地方被关闭
                _cv_push.wait(lock, [&]{ return !full() || _state != State::OPEN; });
            }
        }

        if (_state == State::CLOSED) {
            // throw std::runtime_error("Trying to push to a closed queue.");
            return;
        }

        _current_size++;
        _queue.push(v);

        _cv_pop.notify_one();
    }

    int pop(T& v) {
        std::unique_lock<std::mutex> lock(_mutex);
        // 当队列为空且队列未被关闭时，等待数据压入
        _cv_pop.wait(lock, [&]{ return !empty() || _state == State::CLOSED; });
        if (empty() && _state == State::CLOSED) {
            return 0;
        }
        
        _current_size--;
        v = _queue.front();

        _cv_push.notify_one();

        return 1;
    }

    // 关闭队列
    void close() noexcept {
        std::unique_lock<std::mutex> lock(_mutex);
        _state = State::CLOSED;
        _cv_push.notify_all();
        _cv_pop.notify_all();
    }
};

#endif //THREAD_SAFE_QUEUE_HPP
