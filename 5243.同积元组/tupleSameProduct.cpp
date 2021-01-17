class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int>cal_map;

        for(int i=0;i<nums.size()-1;++i)
        {
            for(int j=i+1;j<nums.size();++j)
            {
                int cal_temp=nums[i]*nums[j];
                cal_map[cal_temp]++;
            }
        }

        int count=0;
        for(auto iter=cal_map.begin();iter!=cal_map.end();++iter)
        {
            if(iter->second>=2)
            {
                int temp=1;
                temp=2*2*(iter->second-1)*(iter->second);
                count=count+temp;
            }
        }

        return count;
    }
};