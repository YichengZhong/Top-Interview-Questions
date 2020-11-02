class Solution {
public:
    vector<string>v_temp;
    string removeDuplicateLetters(string s) {
        set<char>set_count;

        for(int i=0;i<s.size();++i)
        {
            set_count.insert(s[i]);
        }

        int count=set_count.size();

        helpDFS(s, "", 0, count);

        sort(v_temp.begin(),v_temp.end());

        return v_temp[0];

    }

    void helpDFS(string s,string temp,int index ,int count)
    {
        if(temp.size()==count)
        {
            v_temp.push_back(temp);
        }

        for(int i=index;i<s.size();++i)
        {
            if(temp.find(s[i])==temp.npos)
            {
                helpDFS(s,temp+s[i],i+1 ,count);
            }
        }
    }
    
};