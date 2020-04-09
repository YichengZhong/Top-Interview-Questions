class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> v_out;
        v_out.clear();
        
        for(int i=0;i<A.size();++i)
        {
            v_out.push_back(A[i]*A[i]);
        }
        
        sort(v_out.begin(),v_out.end());
        
        return v_out;
        
    }
};