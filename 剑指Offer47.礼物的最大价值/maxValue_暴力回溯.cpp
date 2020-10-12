class Solution {
public:
    int outValue;
    int maxValue(vector<vector<int>>& grid) {
        outValue=0;

        helpDFS(grid,0,0,0);

        return outValue;
    }

    void helpDFS(vector<vector<int>>& grid,int index_i,int index_j,int sum)
    {
        if(index_i>=grid.size() || index_j>=grid[0].size())
        {
            outValue=max(outValue,sum);
            return;
        };
        
        if(index_i>=grid.size() || index_j>=grid[0].size())
        {
            return;
        }

        helpDFS(grid,index_i+1,index_j,sum+grid[index_i][index_j]);
        helpDFS(grid,index_i,index_j+1,sum+grid[index_i][index_j]);
    }
};