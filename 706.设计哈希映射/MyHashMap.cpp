

class MyHashMap {
private:
    constexpr static int maxSize = 1021;
    // pair<int,int> 是pair<key, value>
    vector<list<pair<int, int>>> v;

    int GetIndex(int x)
    {
        return x % maxSize;
    }
public:
    /** Initialize your data structure here. */
    MyHashMap() : v(maxSize){

    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int i = GetIndex(key);
        for (auto iter = v[i].begin(); iter != v[i].end(); ++iter)
        {
            // 已存在需要删除
            if ((*iter).first == key)
            {
                v[i].erase(iter);
                break;
            }
        }
        v[i].emplace_back(key, value);
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int i = GetIndex(key);
        for (auto iter = v[i].begin(); iter != v[i].end(); ++iter)
        {
            // 找到则返回
            if ((*iter).first == key)
            {
                return (*iter).second;
            }
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int i = GetIndex(key);
        for (auto iter = v[i].begin(); iter != v[i].end(); ++iter)
        {
            if ((*iter).first == key)
            {
                // 删除存在的结点
                v[i].erase(iter);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
