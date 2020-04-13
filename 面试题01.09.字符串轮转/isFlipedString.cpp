class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if(s1.size()==0 && s2.size()==0)
        {
            return true;
        }
        string s3=s2+s2;

        return s1.size()==s2.size()&&s3.find(s1)!=-1;

    }
};