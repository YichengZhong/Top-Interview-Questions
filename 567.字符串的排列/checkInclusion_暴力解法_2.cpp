class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size())
            return false;

        int windows_size=s1.size();

        string s1_temp=s1;
        sort(s1_temp.begin(),s1_temp.end());

        for(int i=0;i<=s2.size()-windows_size;++i)
        {
            string temp=s2.substr(i,windows_size);
            sort(temp.begin(),temp.end());

            if(temp==s1_temp)
                return true;
        }

        return false;
    }
};