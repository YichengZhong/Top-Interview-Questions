class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int count=0;

        int left=0,right=0;
        int sum=0;
        vector<int>v_len;
        while(right<arr.size())
        {
            sum=sum+arr[right];
            right++;

            while(sum>target)
            {
                sum=sum-arr[left];
                left++;
            }

            if(sum==target)
            {
                count++;
                v_len.push_back(right-left);
                left=right;
                sum=0;
            }
        }

        if(count<2)
        {
            return -1;
        }

        sort(v_len.begin(),v_len.end());

        return v_len[0]+v_len[1];

    }
};