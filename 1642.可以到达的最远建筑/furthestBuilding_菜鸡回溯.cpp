class Solution {
public:
    int maxLen;
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        maxLen=0;

        helpDFS(heights,bricks,ladders,0);

        return maxLen;
    }

    void helpDFS(vector<int>& heights, int bricks, int ladders,int index)
    {
        if(index>=heights.size())
        {
            return;
        }

        if(maxLen<index)
        {
            maxLen=max(maxLen,index);
        }

        //不需要辅助
        if((index+1)<heights.size() && heights[index]>=heights[index+1])
        {
            helpDFS(heights,bricks,ladders,index+1);
        }
        //需要辅助
        if( ((index+1)<heights.size()) &&heights[index]<heights[index+1] && (bricks>0 || ladders>0))
        {
            //使用砖块
            if(bricks>=abs(heights[index+1]-heights[index]))
            {
                helpDFS(heights,bricks-abs(heights[index+1]-heights[index]),ladders,index+1);
            }

            //使用梯子
            if(ladders>0)
            {
                helpDFS(heights,bricks,ladders-1,index+1);
            }
        }
        else
        {
            return;
        }
    }
};