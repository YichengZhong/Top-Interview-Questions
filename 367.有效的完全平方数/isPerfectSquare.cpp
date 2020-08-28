class Solution {
public:
    bool isPerfectSquare(int num) {
        int num1 = 1;
        while(num > 0) 
        {
            num -= num1;
            num1 += 2;
        }
        return num == 0;

    }
};