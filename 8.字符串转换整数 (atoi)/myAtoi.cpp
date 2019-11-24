class Solution {
public:
    int myAtoi(string str) {
        int i=0;
        while(i<str.size() && str[i]==' ') 
        {
            ++i;
        }
        if(i >= str.size()) 
        {
            return 0;
        }
        int s=1;
        if(str[i] == '-') 
        {
            s=-1;
            ++i;
        }
        else if(str[i] == '+') 
        {
            ++i;
        }

        long long ans=0;
        while(i<str.size() && isdigit(str[i]))
        {
            if(ans > INT_MAX) 
            {
                break;
            }
            ans = 10 * ans + (str[i] - '0');
            ++i;
        } 
        if(s > 0)
        {
            if(ans > INT_MAX) 
                return INT_MAX;
            return ans;
        }else if(s < 0)
        {
            if(ans > INT_MAX) 
                return INT_MIN;
            return ans*s;
        }
        return ans;
    }
};