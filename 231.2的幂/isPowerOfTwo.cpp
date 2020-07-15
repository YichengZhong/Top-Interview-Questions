class Solution {
public:
    bool isPowerOfTwo(int n) {
           double res = log10(n) / log10(2);
        return (res - (int)(res) == 0) ? true : false;
        
    }
};