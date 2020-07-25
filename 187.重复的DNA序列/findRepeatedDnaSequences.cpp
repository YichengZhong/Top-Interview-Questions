class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
         unordered_map<string, int> mp;
         vector<string>v_out;
         v_out.size();

         if(s.size()<=10)
         {
             return v_out;
         }

         for(int i=0;i<=s.size()-10;++i)
         {
             string temp=s.substr(i,10);
             mp[temp]++;
         }

         for(auto it=mp.begin();it!=mp.end();++it)
         {
             if(it->second>1)
             {
                 v_out.push_back(it->first);
             }
         }

         return v_out;

    }
};