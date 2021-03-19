class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        double orgsum = 0;
        for(int i = 0; i < nums.size(); i++)orgsum += nums[i];
        double DiffBetweenSumandGoal=fabs(orgsum-goal);
        
        return ceil(DiffBetweenSumandGoal / (double)limit);
    }
};