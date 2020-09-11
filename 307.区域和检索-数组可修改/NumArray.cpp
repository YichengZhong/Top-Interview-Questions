class NumArray {
public:
    vector<int>num;
    NumArray(vector<int> nums) 
    {
        num.resize(nums.size()+1,0);
        num[0]=0;
        for(int i=0;i<nums.size();i++){
            num[i+1]=nums[i]+num[i];
        }
    }
    
    void update(int i, int val) 
    {
        int den=val-(num[i+1]-num[i]);
        for(i++;i<num.size();i++)
            num[i]+=den;
    }
    
    int sumRange(int i, int j) 
    {
        return num[j+1]-num[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */