class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>str_nums;
        str_nums.clear();
        
        if(0==nums.size())
        {
            return "";
        }
        
        for(int i=0;i<nums.size();++i)
        {
            str_nums.push_back(to_string(nums[i]));
        }
        
        sort(str_nums.begin(),str_nums.end());
        
        reverse(str_nums.begin(),str_nums.end());
        
        string str_out="";
        
        for(int i=0;i<str_nums.size();++i)
        {
            str_out=str_out+str_nums[i];
        }
        
        return str_out;
        
    }
};