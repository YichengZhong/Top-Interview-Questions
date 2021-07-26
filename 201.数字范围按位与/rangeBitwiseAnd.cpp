class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int mask = 1 << 30; // 最高位开始
        int anw = 0;
        while(mask > 0 && (m&mask) == (n&mask)) { //寻找相同前缀
            anw |= m&mask;
            mask >>= 1;
        }
        return anw;
    }
};