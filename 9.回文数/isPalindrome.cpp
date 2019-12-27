class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        
        vector<int>v_temp;
        v_temp.clear();
        
        int temp=x;
        while(temp!=0)
        {
            v_temp.push_back(temp%10);
            temp=temp/10;
        }
        
        for(int i=0;i<v_temp.size();++i)
        {
            if(v_temp[i]!=v_temp[v_temp.size()-1-i])
            {
                return false;
            }
        }
        
        return true;
        
    }
};