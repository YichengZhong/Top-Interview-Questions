class Solution {
public:
    int minCharacters(string a, string b) {
        //模拟大法
        int minCount=a.size()+b.size();
        minCount=min(minCount,SituationOne(a,b));
        minCount=min(minCount,SituationTwo(a,b));
        minCount=min(minCount,SituationThree(a,b));
        
        return minCount;
    }

    int SituationOne(string a, string b)
    {
        int minCount=a.size()+b.size();
        //遍历字母表，找到最小。

        for(char i='a';i<='z';++i)
        {
            int temp=0;
            for(int j=0;j<a.size();++j)
            {
                if(a[j]>i) temp++;
            }
            for(int j=0;j<b.size();++j)
            {
                if(b[j]<=i) temp++;
            }

            minCount=min(minCount,temp);
        }

        return minCount;
    }

    int SituationTwo(string a, string b)
    {
        int minCount=a.size()+b.size();

        for(char i='a';i<='z';++i)
        {
            int temp=0;
            for(int j=0;j<a.size();++j)
            {
                if(a[j]<i) temp++;
            }
            for(int j=0;j<b.size();++j)
            {
                if(b[j]>=i) temp++;
            }
            minCount=min(minCount,temp);
        }

        return minCount;
    }

    int SituationThree(string a, string b)
    {
        int minCount=a.size()+b.size();

        for(char i='a';i<='z';++i)
        {
            int temp=0;
            for(int j=0;j<a.size();++j)
            {
                if(a[j]!=i) temp++;
            }
            for(int j=0;j<b.size();++j)
            {
                if(b[j]!=i) temp++;
            }

            minCount=min(minCount,temp);
        }

        return minCount;
    }


};