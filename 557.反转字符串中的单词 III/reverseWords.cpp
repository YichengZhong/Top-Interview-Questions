class Solution {
public:
    // 反转字符串
    void reverseString(int front, int tail, string& str) 
    {
        while (front < tail) 
        {
            str[front] ^= str[tail];
            str[tail] ^= str[front];
            str[front++] ^= str[tail--];
        }
    }
    
    // 确定单词边界
    string reverseWords(string s) 
    {
        int front = 0;
        for (int i = 0; i < s.length(); i++) 
        {
            if (s[i] == ' ') 
            {
                reverseString(front, i - 1, s);
                front = i + 1;
            }
        }
        
        reverseString(front, s.length() - 1, s);
        return s;
    }
};