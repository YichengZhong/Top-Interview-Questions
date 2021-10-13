class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        const int n = list1.size(), m = list2.size();
        unordered_map<string, int> myMap; //记录第一个list的下标
        vector<string> ans;
        int minn = n + m + 1;
        for(int i = 0; i < n; ++i) myMap[list1[i]] = i;  //记录list1的下标
        for(int i = 0; i < m; ++i){  //遍历list2
            if(myMap.find(list2[i]) != myMap.end()){ //如果能在myMap里找到
                if(minn > i + myMap[list2[i]]){  //下标加和比minn小
                    minn = i + myMap[list2[i]];
                    ans.clear();             //清空ans
                    ans.push_back(list2[i]); //放入答案
                }else if(minn == i + myMap[list2[i]]) ans.push_back(list2[i]);//相等时
            }
        }
        return ans;
    }
};