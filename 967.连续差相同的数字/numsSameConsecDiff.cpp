class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int>v_out;

        if (N == 1) return vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

        for (int i = 1; i <= 9; i++)
        {
            helper( i, N - 1, K,v_out);      
        }

        return v_out;
    }

    void helper(int curt,int N,int K,vector<int>&v_out)
    {
        if (N == 0) 
        {    
            v_out.push_back(curt);
            return;
        }
        int last = curt % 10;
        if(K==0)
        {
            helper( curt * 10 + last, N - 1, K,v_out);
        }
        else
        {
            if (last + K <= 9)
            {
                helper( curt * 10 + last + K, N - 1, K,v_out);
            }

           
            if (last - K >= 0)
            {
                helper( curt * 10 + last - K, N - 1, K,v_out);
            }
            
        }
        
    }

    
};