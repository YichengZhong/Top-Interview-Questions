class Solution {
public:
    int maxLen;
    int findMaxForm(vector<string>& strs, int m, int n) {
        maxLen=0;
        vector<string> temp;

        helpDFS(strs,temp,0,0,0,m,n);
        return maxLen;
    }

    void helpDFS(vector<string>& strs,vector<string> &temp, int temp_m,int temp_n,int index, int m, int n)
    {
        maxLen=maxLen>temp.size()?maxLen:temp.size();
        if(index>=strs.size()) return;

        for(int i=index;i<strs.size();++i)
        {
            int onecount=getOneNum(strs[i]);
            int zerocount=getZeroNum(strs[i]);

            if((temp_m+zerocount)<=m && (temp_n+onecount)<=n)
            {
                temp.push_back(strs[i]);
                helpDFS(strs,temp,temp_m+zerocount,temp_n+onecount,i+1,m,n);
                temp.pop_back();
            }
        }
    }

    int getOneNum(string &str)
    {
        int count=0;
        for(int i=0;i<str.size();++i)
        {
            if(str[i]=='1') count++;
        }

        return count;
    }

    int getZeroNum(string &str)
    {
        int count=0;
        for(int i=0;i<str.size();++i)
        {
            if(str[i]=='0') count++;
        }

        return count;
    }
};