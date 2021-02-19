class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        //第一反应回溯，后来觉得滑动窗口
        int res = 0, zeros = 0, left = 0;
        for (int right = 0; right < A.size(); ++right) 
        {
            if (A[right] == 0) ++zeros;
            while (zeros > K) 
            {
                if (A[left++] == 0) --zeros;
            }
            
            res = max(res, right - left + 1);
        }
        return res;
    }
};