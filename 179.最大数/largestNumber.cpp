bool compare(string a,string b)
{
    if(atoll((a+b).c_str())>atoll((b+a).c_str()))
    {
        return true;
    }
    
    return false;
}

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
        
        sort(str_nums.begin(),str_nums.end(),compare);
        
        //reverse(str_nums.begin(),str_nums.end());
        
        string str_out="";
        
        for(int i=0;i<str_nums.size();++i)
        {
            str_out=str_out+str_nums[i];
        }

        if(atoll(str_out.c_str())==0)
        {
            return "0";
        }
        
        return str_out;
        
    }
};