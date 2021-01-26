class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        queue<string>que_str;
        set<string>set_str;

        que_str.push(s);
        set_str.insert(s);

        while(que_str.size()>0)
        {
            for(int i=0;i<pairs.size();++i)
            {
                string temp=que_str.front();
                swap(temp[pairs[i][0]],temp[pairs[i][1]]);

                if(set_str.find(temp)==set_str.end())
                {
                    que_str.push(temp);
                    set_str.insert(temp);
                }
            }
            que_str.pop();
        }

        return *(set_str.begin());
    }
};