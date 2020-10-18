class Solution {
public:
    int minValue;
    int minimumTotal(vector<vector<int>>& triangle) {
        minValue=INT_MAX;

        helpDFS(triangle,0,0,0);

        return minValue;
    }

    void helpDFS(vector<vector<int>>& triangle,int index_i,int index_j,int sum)
    {
        if(index_i>=triangle.size())
        {
            minValue=min(minValue,sum);
            return;
        };

        if(index_i>=triangle.size() || index_j>=triangle[index_i].size())
        {
            return;
        }

        helpDFS(triangle,index_i+1,index_j,sum+triangle[index_i][index_j]);
        helpDFS(triangle,index_i+1,index_j+1,sum+triangle[index_i][index_j]);
    }


};