class NumArray {
public:

vector<int>v_sumIndex;

    NumArray(vector<int>& nums) {
        v_sumIndex.clear();

        int sum=0;
        for(int i=0;i<nums.size();++i)
        {
            sum=sum+nums[i];
            v_sumIndex.push_back(sum);
        }

    }
    
    int sumRange(int i, int j) {

        if(i==0)
        {
            return v_sumIndex[j];
        }

        return v_sumIndex[j]-v_sumIndex[i-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */