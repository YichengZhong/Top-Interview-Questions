class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(),s.end());

        int left=0,right=0;
        while(right<s.size())
        {
            while(right<s.size() && s[right]!=' ')
            {
                right++;
            }

            if(right>s.size())
            {
                right=right-1;
            }

            reverse(s.begin()+left,s.begin()+right);

            left=right+1;
            right=right+1;
        }
    }
};