class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        bool flag1 = true;
        bool flag2 = true;
        for(int i = 0; i < s1.size(); i++) 
        {
            if(flag1 == true && s1[i] < s2[i]) 
            {
                flag1 = false;
            }
            
            if(flag2 == true && s1[i] > s2[i]) 
            {
                flag2 = false;
            }
           
            if(flag1 == false && flag2 == false) 
            {
                return false;
            }
            
        }
        return true;
    }
};