class Solution {
public:
    vector<int> shortestSeq(vector<int>& big, vector<int>& small) {
        int left=0,right=0;
        multiset<int>windows;
        int maxlen=big.size()+1;
        vector<int>v_out;
        v_out.clear();

        while(right<big.size())
        {
            windows.insert(big[right]);
            right++;

            while(isIncludeSmall(windows,small))
            {
                windows.erase(find(windows.begin(),windows.end(),big[left]));
                left++;

                if(maxlen>(right-left))
                {
                    maxlen=right-left;
                    v_out.clear();
                    v_out.push_back(left-1);
                    v_out.push_back(right-1);
                }
            }
        }
        return v_out;
    }

    bool isIncludeSmall(multiset<int>&windows, vector<int>& small)
    {
        for(int i=0;i<small.size();++i)
        {
            if(find(windows.begin(),windows.end(),small[i])==windows.end()) return false;
        }
        return true;
    }
};