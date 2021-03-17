class Solution {
public:
    bool checkPowersOfThree(int n) {
        //三进制啊！！
        while (n != 0) 
        {
            if (n % 3 > 1) return false;
            n = n / 3;
        }
        return true;
    }
};