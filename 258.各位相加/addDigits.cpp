class Solution {
public:
    int addDigits(int num) {
        int res=num;
        while(true)
        {
            if(res < 10) return res;
            num=res;//每次把上次的结果res作为num重新计算
            res=0;//将本次res重置为0
            while(num)
            {
                res += num%10;
                num /= 10;
            }
        }

    }
};