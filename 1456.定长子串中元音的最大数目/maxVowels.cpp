class Solution {
public:
    int check(char c)
    {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') 
        {
            return 1;
        }
        return 0;
    } 
    int maxVowels(string s, int k) 
    {
        int left = 0, right = 0;
        int temp=0,maxlen=0;

        while(right<s.size())
        {
            char c=s[right];
            temp=temp+check(c);

            while((right-left)>=k)
            {
                char d=s[left];
                temp=temp-check(d);
                left++;
            }

            right++;

            maxlen=max(maxlen,temp);
        }

        return maxlen;

    }
};