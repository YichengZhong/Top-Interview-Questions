class Solution {
public:
    string getSmallestString(int n, int k) {
        string res(n, 'a');
        int bound = (k - n) / 25; // 需要置为 ‘z’的数量
        int r = (k - n) % 25; // 第一个 z 前面那位
        if (n - bound - 1 >= 0) res[n-bound-1] = 'a' + r;
        for (int i = n - bound; i < n; i++) 
        {
            res[i] = 'z';
        }
        return res;
    }
};