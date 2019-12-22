/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 *
 * https://leetcode.com/problems/lru-cache/description/
 *
 * algorithms
 * Hard (24.83%)
 * Likes:    3151
 * Dislikes: 111
 * Total Accepted:    315.9K
 * Total Submissions: 1.2M
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
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
 * 
 * 
 *  
 * 
 * 
 * 
 * 
 */
class LRUCache {
public:
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        auto it=m.find(key);
        if(it==m.end())return -1;
        l.splice(l.begin(),l,it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it=m.find(key);
        if(it!=m.end())l.erase(it->second);
        l.push_front(make_pair(key,value));
        m[key]=l.begin();
        if(m.size()>cap){
            int k=l.rbegin()->first;
            l.pop_back();
            m.erase(k);
        }
    }
private:
    int cap;
    list<pair<int,int>>l;
    unordered_map<int,list<pair<int,int>>::iterator>m;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

