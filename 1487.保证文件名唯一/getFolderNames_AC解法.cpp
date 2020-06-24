class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
       int n = names.size();
        unordered_map<string, int> M;
        vector<string> res;
        for(int i = 0; i < n; i++)
        {
            string tmp = "";
            if(M.find(names[i]) == M.end())
            {
                M[names[i]] = 1;
                tmp = names[i];  
            }
            else
            {
                int k = M[names[i]];
                tmp =  names[i] + '(' + to_string(k) + ')';
                while(M.find(tmp) != M.end())
                {
                    k++;
                    tmp =  names[i] + '(' + to_string(k) + ')';
                }    
                M[names[i]] = k+1;
                M[tmp] = 1;
            }
            res.push_back(tmp);
        }
        return res;
    }
};