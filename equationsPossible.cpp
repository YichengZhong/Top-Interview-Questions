class Solution {
public:
    //模拟大法
    bool equationsPossible(vector<string>& equations) {
        int digMap[26][26]={0};

        //0：未知
        //1：相等
        //-1：不等
        for(int i=0;i<26;++i)
            digMap[i][i]=1;

        for(int i=0;i<equations.size();++i)
        {
            char firtchr=equations[i][0];
            char secondchr=equations[i][3];
            char flag=equations[i][1];

            //第一次遇见了
            if(digMap[firtchr-'a'][secondchr-'a']==0)
            {
                if(flag=='=')
                {
                    digMap[firtchr-'a'][secondchr-'a']=1;
                    digMap[secondchr-'a'][firtchr-'a']=1;
                }
                else
                {
                    digMap[firtchr-'a'][secondchr-'a']=(-1);
                    digMap[secondchr-'a'][firtchr-'a']=(-1);
                }
            }
            else if(digMap[firtchr-'a'][secondchr-'a']==1)
            {
                if(flag=='!')
                {
                    return false;
                }
            }
            else if(digMap[firtchr-'a'][secondchr-'a']==(-1))
            {
                if(flag=='=')
                {
                    return false;
                }
            }
        }

    }
};