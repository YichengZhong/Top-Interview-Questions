class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxAverage=(-INT_MAX);
        int tempsun=accumulate(nums.begin(),nums.begin()+k,0);
        double tempAverage=(double)tempsun/k;
        maxAverage=maxAverage>tempAverage?maxAverage:tempAverage;

        for(int i=k;i<nums.size();++i)
        {
            tempsun=tempsun-nums[i-k]+nums[i];
            tempAverage=(double)tempsun/(double)k;
            maxAverage=maxAverage>tempAverage?maxAverage:tempAverage;
        }

        return maxAverage;
    }
};