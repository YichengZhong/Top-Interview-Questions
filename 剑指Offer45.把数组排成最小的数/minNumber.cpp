bool mycompare(int a,int b)
{
    string ab=to_string(a)+to_string(b);
    string ba=to_string(b)+to_string(a);

    if(stoll(ab)<stoll(ba))
    {
        return true;
    }
    
    return false;
}

class Solution {
public:
    string minNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),mycompare);

        string str_out="";

        for(int i=0;i<nums.size();++i)
        {
            str_out=str_out+to_string(nums[i]);
        }

        return str_out;
    }
};