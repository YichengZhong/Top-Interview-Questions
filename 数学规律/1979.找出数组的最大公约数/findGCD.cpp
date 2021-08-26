class Solution {
public:
    int gcd(int x,int y)
    {
        int r;
        if(x<y)
        {
            r=x;
            x=y;
            y=r;
        }
        r=x%y;
        while(r)
        {
            x=y;
            y=r;
            r=x%y;
        }
        
        return y;
    }
    
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        return gcd(nums[0],nums[nums.size()-1]);
    }
};