class MapSum {
public:
    /** Initialize your data structure here. */
    unordered_map<string,int> string_val;
    MapSum() {

    }
    
    void insert(string key, int val) {
        string_val[key]=val;
    }
    
    int sum(string prefix) {
        int value=0;

        for(auto iter=string_val.begin();iter!=string_val.end();++iter)
        {
            string temp=(iter->first);
            if(temp.find(prefix)==0)
            {
                value=value+iter->second;
            }
        }

        return value;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */