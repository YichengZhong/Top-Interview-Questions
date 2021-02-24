class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        vector<vector<int>>out=A;

        for(int i=0;i<out.size();++i)
        {
            reverse(out[i].begin(),out[i].end());
            for(int j=0;j<out[i].size();++j)
            {
                if(out[i][j]==1) out[i][j]=0;
                else out[i][j]=1;
            }
        }

        return out;
    }
};