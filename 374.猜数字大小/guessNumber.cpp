// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) 
    {
        int t = guess(n);
        if(t==0)
        {
            return n;
        }
        int left = 1,right = n;
        while(left<right)
        {
            int mid = left + (right-left)/2;
            int x = guess(mid);
            if(x==1)
            {
                left = mid;
            }
            else if(x==-1)
            {
                right = mid;
            }
            else if(x==0)
            {
                return mid;
            }
        }
    }
};