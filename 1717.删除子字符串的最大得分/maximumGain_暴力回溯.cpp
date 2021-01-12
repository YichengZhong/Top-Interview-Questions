class Solution {
public:
    int maxValue;
    int maximumGain(string s, int x, int y) {
        //回溯
        maxValue=0;
        helpDFS(s,x,y,0);

        return maxValue;
    }

    void helpDFS(string s,int x,int y,int Value)
    {
        maxValue=max(maxValue,Value);

        if(s.find("ab")==string::npos && s.find("ba")==string::npos) return;

        //删除字串"ab"
        int index=string::npos;
        index=s.find("ab");
        if(index!=string::npos)
        {
            string temp=s;
            helpDFS(temp.erase(index,2),x,y,Value+x);
        }

        //删除字串"ba"
        index=s.find("ba");
        if(index!=string::npos)
        {
            string temp=s;
            helpDFS(temp.erase(index,2),x,y,Value+y);
        }
        
    }
};