class Solution {
public:
    int count;
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        count=0;
        
        if(obstacleGrid[0][0]==1) return count;

        helpDFS(obstacleGrid,0,0);

        return count;
    }

    void helpDFS(vector<vector<int>>& obstacleGrid,int index_x,int index_y)
    {
        if(index_x>=obstacleGrid.size()-1 && index_y>=obstacleGrid[0].size()-1 && obstacleGrid[index_x][index_y]==0)
        {
            count++;
        }

        //可以横着走
        if((index_x+1)<obstacleGrid.size() && index_y<obstacleGrid[0].size())
        {
            if(obstacleGrid[index_x+1][index_y]!=1)
            {
                helpDFS(obstacleGrid,index_x+1,index_y);
            }
        }

        //可以竖着走
        if((index_y+1)<obstacleGrid[0].size() && index_x<obstacleGrid.size())
        {
            if(obstacleGrid[index_x][index_y+1]!=1)
            {
                helpDFS(obstacleGrid,index_x,index_y+1);
            }
        }
    }
};