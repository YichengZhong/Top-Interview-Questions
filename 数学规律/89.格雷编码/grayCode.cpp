class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        int powN = 1 << n;
        for(int i = 0; i < powN; ++i)
            ans.push_back(i^i>>1);
        return ans;
    }
};