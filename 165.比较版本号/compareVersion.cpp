class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<string>v_str1;
        vector<string>v_str2;
        
        splitstring(version1,v_str1);
        splitstring(version2,v_str2);
        
        int i=0,j=0;
        
        while(i!=v_str1.size() || j!=v_str2.size())
        {
            if(i<v_str1.size() && j<v_str2.size())
            {
                int n1 = atoi(v_str1[i].c_str());
                int n2 = atoi(v_str2[j].c_str());
                
                if(n1>n2)
                {
                    return 1;
                }
                if(n1<n2)
                {
                    return -1;
                }
                
                i++;
                j++;
            }
            
            if(i<v_str1.size() && j>=v_str2.size())
            {
                int n1 = atoi(v_str1[i].c_str());
                int n2 = 0;
                
                if(n1>n2)
                {
                    return 1;
                }
                if(n1<n2)
                {
                    return -1;
                }
                
                i++;
            }
            
            if(i>=v_str1.size() && j<v_str2.size())
            {
                int n1 = 0;
                int n2 = atoi(v_str2[j].c_str());
                
                if(n1>n2)
                {
                    return 1;
                }
                if(n1<n2)
                {
                    return -1;
                }
                
                j++;
            }
            
        }
        
        return 0;
        
        
        
    }
    
    void splitstring(string str,vector<string>&v_str)
    {
        string str_split=".";
        int size_pos=0;
        int size_pre_pos=0;
        string strResult="";
        
        while((size_pos=str.find_first_of(str_split,size_pos))!=string::npos)
        {
            strResult=str.substr(size_pre_pos,size_pos-size_pre_pos);
            v_str.push_back(strResult);
            size_pre_pos=++size_pos;
        }
        
        if(size_pre_pos!=str.size())
        {
            strResult=str.substr(size_pre_pos,size_pos-size_pre_pos);
            v_str.push_back(strResult);
        }
        
    }
};