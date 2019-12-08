class Solution {
public:
    bool isPowerOfThree(int n) {
        double res = log10(n) / log10(3);
        return (res - (int)(res) == 0) ? true : false;
    }
};