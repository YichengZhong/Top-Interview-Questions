class Solution {
public:
    string removeDuplicates(string S) {
        int len=S.size();
        stack<char> ver;  //定义栈

        for(int i=0;i<len;i++)
        {
            if (ver.empty() || S[i] != ver.top()) 
            {
                ver.push(S[i]);
            } else 
            {
                ver.pop(); // s 与 st.top()相等的情况
            }
        }
        string result="";
        while(!empty(ver))
        {
            result+=ver.top();
            ver.pop();
        }
        reverse (result.begin(), result.end());
        return result;     
    }
};