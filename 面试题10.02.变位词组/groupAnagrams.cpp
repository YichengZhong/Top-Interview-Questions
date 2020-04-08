class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> v_v_out;
        v_v_out.clear();
        
        if(strs.size()==0)
        {
            return v_v_out;
        }
        
        map<string,vector<string>> str_map;
        map<string,vector<string>>::iterator iter;
        
        for(int i=0;i<strs.size();++i)
        {
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            
            if(str_map.end() == str_map.find(temp))
            {
                vector<string>v_str;
                v_str.clear();
                v_str.push_back(strs[i]);
                str_map[temp]=v_str;
            }
            else
            {
                str_map[temp].push_back(strs[i]);
            }
        }
        
        for(iter=str_map.begin();iter!=str_map.end();++iter)
        {
            v_v_out.push_back((*iter).second);
        }
        
        return v_v_out;
        
    }
};