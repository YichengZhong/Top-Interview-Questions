class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();

        for(int i=0;i<rows;++i)
        {
            for(int j=0;j<cols;++j)
            {
                if((i+1)<rows && (j+1)<cols)
                {
                    if(matrix[i][j]!=matrix[i+1][j+1])
                    {
                        return false;
                    }
                }
            }
        }

        return true;

    }
};