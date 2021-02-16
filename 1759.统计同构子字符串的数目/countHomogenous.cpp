class Solution {
public:
    int countHomogenous(string S) {
        vector<long long>numscount;
        int pre = 0, later = 0;
        while (later <= S.size())
        {
            if (S[pre] == S[later])
                later++;
            else
            {
                numscount.push_back(later - pre);
                pre = later; 
            }
        }

        long long count=0;
        for(int i=0;i<numscount.size();++i)
        {
            count=count+(numscount[i]+1)*numscount[i]/2;
        }

        return count% 1000000007;

    }
};