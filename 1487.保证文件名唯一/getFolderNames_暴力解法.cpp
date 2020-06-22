class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        vector<string>v_out;
        
        unordered_set<string>fileName_count;
        
        for(int i=0;i<names.size();++i)
        {
            if(fileName_count.find(names[i])==fileName_count.end())
            {
                fileName_count.insert(names[i]);
                v_out.push_back(names[i]);
                continue;
            }
            else
            {
                for(int j=1;j<names.size();++j)
                {
                    string temp=names[i]+"("+to_string(j)+")";
                    if(fileName_count.find(temp)==fileName_count.end())
                    {
                        fileName_count.insert(temp);
                        v_out.push_back(temp);
                        break;
                    }
                    
                }
            }            
        }
        
        return v_out;

    }
};