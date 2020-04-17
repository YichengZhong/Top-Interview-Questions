class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int>v_allelm;
        
        v_allelm.clear();
        
        for(int i=0;i<matrix.size();++i)
        {
            for(int j=0;j<matrix[i].size();++j)
            {
                v_allelm.push_back(matrix[i][j]);
            }
        }
        
        sort(v_allelm.begin(),v_allelm.end());
        
        return v_allelm[k-1];
        
    }
};