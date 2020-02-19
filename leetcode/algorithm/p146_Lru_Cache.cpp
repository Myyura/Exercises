/**
 * Myyura
 */

/**
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 *
 * https://leetcode.com/problems/lru-cache/description/
 *
 * algorithms
 * Medium (29.59%)
 * Likes:    4542
 * Dislikes: 196
 * Total Accepted:    432.4K
 * Total Submissions: 1.5M
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n' +
  '[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * Design and implement a data structure for Least Recently Used (LRU) cache.
 * It should support the following operations: get and put.
 * 
 * get(key) - Get the value (will always be positive) of the key if the key
 * exists in the cache, otherwise return -1.
 * put(key, value) - Set or insert the value if the key is not already present.
 * When the cache reached its capacity, it should invalidate the least recently
 * used item before inserting a new item.
 * 
 * The cache is initialized with a positive capacity.
 * 
 * Follow up:
 * Could you do both operations in O(1) time complexity?
 * 
 * Example:
 * LRUCache cache = new LRUCache( 2  |capacity |);
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // returns 1
 * cache.put(3, 3);    // evicts key 2
 * cache.get(2);       // returns -1 (not found)
 * cache.put(4, 4);    // evicts key 1
 * cache.get(1);       // returns -1 (not found)
 * cache.get(3);       // returns 3
 * cache.get(4);       // returns 4
 */

// @lc code=start
class LRUCache {
private:
    std::list<std::pair<int, int>> _sorted_keys;
    // std::unordered_set<int> _keys;
    int _capacity;

public:
    LRUCache(int capacity) : _capacity(capacity) {}
    
    int get(int key) {
        for (auto it = _sorted_keys.begin(); it != _sorted_keys.end(); it++) {
            if (it->first == key) {
                int value = it->second;
                _sorted_keys.push_front(std::make_pair(key, value));
                _sorted_keys.erase(it);
                return value;
            }
        }

        return - 1; 
    }
    
    void put(int key, int value) {
        bool existed = false;
        for (auto it = _sorted_keys.begin(); it != _sorted_keys.end(); it++) {
            if (it->first == key) {
                _sorted_keys.push_front(std::make_pair(key, value));
                _sorted_keys.erase(it);
                existed = true;
                break;
            }
        }

        if (!existed) {
            _sorted_keys.push_front(std::make_pair(key, value));
        }

        if (_sorted_keys.size() > _capacity) {
            _sorted_keys.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
