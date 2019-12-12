class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        vector<int>v_left_max=A;
        vector<int>v_right_min=A;

        if(A.size()==0)
        {
            return 0;
        }

        int left_max=A[0];
        for(int i=0;i<A.size();++i)
        {
            if(left_max<A[i])
            {
                left_max=A[i];
            }

            v_left_max[i]=(left_max);
        }

        int right_min=A[A.size()-1];
        for(int i=A.size()-1;i>=0;--i)
        {
            if(right_min>A[i])
            {
                right_min=A[i];
            }

            v_right_min[i]=(right_min);
        }

        for(int i=1;i<A.size();++i)
        {
            if(v_left_max[i-1]<=v_right_min[i])
            {
                return i;
            }
        }

        return 0;
        
    }
};