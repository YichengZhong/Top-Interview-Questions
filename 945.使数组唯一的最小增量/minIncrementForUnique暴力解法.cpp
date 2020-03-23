class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        sort(A.begin(),A.end());

        int out=0;

        if(A.size()<=1)
        {
            return 0;
        }

        for(int i=0;i<A.size()-1;++i)
        {
            while(A[i]>=A[i+1])
            {
                A[i+1]=A[i+1]+1;
                out++;
            }
        }

        return out;

    }
};