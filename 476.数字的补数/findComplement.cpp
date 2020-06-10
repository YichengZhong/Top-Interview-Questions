class Solution {
public:
    int findComplement(int num) {
        int res = 0;

        int i = 0;

        while (num != 0) {

            if ((num & 0x1) == 0) {

                res += pow(2, i);

            }

            i++;

            num >>= 1;

        }

        return res;
    }
};