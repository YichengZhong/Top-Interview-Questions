class Solution {
public:
    bool isUnique(string astr) {
        if(astr.size()==0) 
        return true;
        int * record = new int[26]();
        for(auto s:astr)
        {
            if(record[s-'a']!=0) 
                return false;
            record[s-'a']++;
        }
        return true;
    }
};