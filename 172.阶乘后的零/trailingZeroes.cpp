class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        for (int i = 1; i <= n; i++)
        {
            int N = i;
            while (N > 0) 
            {
                if (N % 5 == 0)
                {
                    count++;
                    N /= 5;
                } 
                else 
                {
                    break;
                }
            }
        }
        return count;
    }
};