class Solution {
public:
    vector<int> input;
    int target;
    vector<vector<int>> result;
    vector<int> vc;

    void dfs(int index, int sum,int k) 
    {
        // index >= input.size() ，写成 index == input.size() 即可
        // 因为每次都 + 1，在 index == input.size() 剪枝就可以了
        if (sum >= target || index == input.size()) 
        {
            if (sum == target && vc.size()==k) 
            {
                result.push_back(vc);
            }
            return;
        }
        for (int i = index; i < input.size(); i++)
        {
            if (input[i] > target)
            {
                continue;
            }

            // 【我添加的代码在这里】：
            // 1、i > index 表明剪枝的分支一定不是当前层的第 1 个分支
            // 2、input[i - 1] == input[i] 表明当前选出来的数等于当前层前一个分支选出来的数
            // 因为前一个分支的候选集合一定大于后一个分支的候选集合
            // 故后面出现的分支中一定包含了前面分支出现的结果，因此剪枝
            // “剪枝”的前提是排序，升序或者降序均可
            if (i > index && input[i - 1] == input[i])
            {
                continue;
            }

            vc.push_back(input[i]);
            sum += input[i];
            dfs(i + 1, sum,k);
            vc.pop_back();
            sum -= input[i];
        }
    }

    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> candidates;
        candidates.clear();
        
        for(int i=0;i<9;++i)
        {
            candidates.push_back(i+1);
        }
        
        sort(candidates.begin(), candidates.end());
        this->input = candidates;
        this->target = n;
        dfs(0, 0,k);
        return result;
        
        
        
    }
};