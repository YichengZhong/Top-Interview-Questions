class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<int>v_stack;
        vector<string>v_str;
        int j=0;
        for(int i=0;i<n && j<target.size();++i)
        {
            v_str.push_back("Push");
            v_stack.push_back(i+1);

            if(v_stack.back()==target[j])
            {
                j++;
                continue;
            }
            else if(v_stack==target)
            {
                return v_str;
            }
            else
            {
                v_str.push_back("Pop");
                v_stack.pop_back();
            }
        }

        return v_str;
    }
};