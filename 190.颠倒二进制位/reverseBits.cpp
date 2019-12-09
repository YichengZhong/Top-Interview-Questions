class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int res = 0;
        for(int i=0; i<32; i++){
            //每次都处理二进制的最低位, 这样方便进行&操作
            int cur = n&1;
            res = res + (cur<<(31-i));
            //update
            n = n>>1;
        }
        return res;        
    }
};