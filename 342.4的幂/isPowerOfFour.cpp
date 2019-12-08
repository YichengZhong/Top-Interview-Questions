class Solution {
public:
    bool isPowerOfFour(int num) {
        double res = log10(num) / log10(4);
        return (res - (int)(res) == 0) ? true : false;
        
    }
};