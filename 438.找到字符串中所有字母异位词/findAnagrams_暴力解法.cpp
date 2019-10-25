class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int p_size=p.size();
        vector<int> v_out;
        v_out.clear();
        
        if(s.size()==0 || s.size()<p_size)
        {
            return v_out;
        }
        
        sort(p.begin(),p.end());
            
        
        for(int i=0;i<s.size()-p_size+1;++i)
        {
            string str_temp= s.substr(i, p_size);
            sort(str_temp.begin(),str_temp.end());
            
            if(str_temp==p)
            {
                v_out.push_back(i);
            }
        }
        
        return v_out;
        
    }
};