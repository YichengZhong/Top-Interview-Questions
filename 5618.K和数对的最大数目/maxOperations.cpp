class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        /*定义一个哈希表来存储遍历过的元素 key: nums[i] value:出现过的次数*/
        unordered_map<int,int> mymap;
        int length=nums.size(),res=0;
        for(int i=0;i<length;++i){
            auto index_pair=mymap.find(k-nums[i]);//寻找是否出现过目标值
            if(index_pair == mymap.end())
            {
                /*未出现就把本身放进去*/
                auto index_myself=mymap.find(nums[i]);
                if(index_myself == mymap.end())
                {
                    mymap[nums[i]]=1;
                }
                else mymap[nums[i]]+=1;
            }
            else{
                res+=1;
                int pair_nums=mymap[k-nums[i]];
                if (pair_nums==1) mymap.erase(k-nums[i]);
                else mymap[k-nums[i]]-=1;
            }
        }
        return res;
    }
};