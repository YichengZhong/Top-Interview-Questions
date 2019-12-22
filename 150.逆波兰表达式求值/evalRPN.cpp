class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int out=0;
        stack <int> stack_nums;
        
        for(int i=0;i<tokens.size();++i)
        {
            if(stack_nums.empty())
            {
                stack_nums.push(atoi(tokens[i].c_str()));
            }
            
            if(tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="*" && tokens[i]!="/" )
            {
                stack_nums.push(atoi(tokens[i].c_str()));
            }
            
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/" )
            {
                int nums1=stack_nums.top();
                stack_nums.pop();
                int nums2=stack_nums.top();
                stack_nums.pop();
                
                if(tokens[i]=="+")
                {
                    out=nums2+nums1;
                    stack_nums.push(out);
                }
                
                if(tokens[i]=="-")
                {
                    out=nums2-nums1;
                    stack_nums.push(out);
                }
                
                if(tokens[i]=="*")
                {
                    out=nums2*nums1;
                    stack_nums.push(out);
                }
                
                if(tokens[i]=="/")
                {
                    out=nums2/nums1;
                    stack_nums.push(out);
                }
            }           
        }
        
        return stack_nums.top();
        
    }
};