class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(0==matrix.size())
        {
            return;
        }

        vector<int>v_rank;
        vector<int>v_column;

        v_rank.clear();
        v_column.clear();

        for(int i=0;i<matrix.size();++i)
        {
            for(int j=0;j<matrix[i].size();++j)
            {
                if(matrix[i][j]==0)
                {
                    v_rank.push_back(i);
                    v_column.push_back(j);
                }
            }
        }

        for(int i=0;i<matrix.size();++i)
        {
            for(int j=0;j<matrix[i].size();++j)
            {
                if(find(v_rank.begin(),v_rank.end(),i)!=v_rank.end() || find(v_column.begin(),v_column.end(),j)!=v_column.end())
                {
                    matrix[i][j]=0;
                }
            }
        }
        
    }
};