class Solution {
public:
    int count;
    int uniquePaths(vector<vector<int>>& obstacleGrid) {
        count=0;

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
            helpDFS(obstacleGrid,index_x+1,index_y);
        }

        //可以竖着走
        if((index_y+1)<obstacleGrid[0].size() && index_x<obstacleGrid.size())
        {
            helpDFS(obstacleGrid,index_x,index_y+1);
        }
    }
};