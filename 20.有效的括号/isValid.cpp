class Solution {
public:
    bool isValid(string s) {
        stack<char>stack_temp;
        
        for(int i=0;i<s.size();++i)
        {
            if(stack_temp.empty())  
                stack_temp.push(s[i]);  
            else if(stack_temp.top()=='('&&s[i]==')'||  
                    stack_temp.top()=='['&&s[i]==']'||  
                    stack_temp.top()=='{'&&s[i]=='}')   
                   stack_temp.pop();  
            else  
                stack_temp.push(s[i]);  
        }
        
        if(stack_temp.empty()==true)
        {
            return true;
        }
        
        return false;
        
    }
};