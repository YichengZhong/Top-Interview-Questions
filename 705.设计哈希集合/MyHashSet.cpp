class MyHashSet {
public:
    /** Initialize your data structure here. */
    vector<int>inerset;
    MyHashSet() {
        inerset.clear();
    }
    
    void add(int key) {
        if(find(inerset.begin(),inerset.end(),key)==inerset.end())
        {
            inerset.push_back(key);
        }

        return ;        
    }
    
    void remove(int key) {
        auto keyiter=find(inerset.begin(),inerset.end(),key);
        if(keyiter!=inerset.end())
        {
            inerset.erase(keyiter);
        }
        return ; 
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        auto keyiter=find(inerset.begin(),inerset.end(),key);
        if(keyiter!=inerset.end())
        {
            return true;
        }
        return false;
    }
};