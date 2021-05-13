class Solution {
public:
    long long glob_count;
    int numWays(int steps, int arrLen) {
        glob_count=0;

        helpDFS(0,steps,arrLen,0);
        return glob_count%1000000007;
    }

    void helpDFS(int steps_left,int steps,int arrLen,int nowindex)
    {
        if(nowindex<0 || nowindex>=arrLen) return;
        if(steps_left>=steps)
        {
            if(nowindex==0) glob_count++;
            return;
        }
        
        //有三种情况
        //向右
        helpDFS(steps_left+1,steps,arrLen,nowindex-1);

        //向左
        helpDFS(steps_left+1,steps,arrLen,nowindex+1);

        //不动
        helpDFS(steps_left+1,steps,arrLen,nowindex);
    }
};