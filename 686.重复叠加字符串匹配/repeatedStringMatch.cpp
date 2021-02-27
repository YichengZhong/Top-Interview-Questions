class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int maxlen=max(b.size()/a.size()+1,a.size()/b.size()+1);
        string temp="";
        for(int i=0;i<=maxlen;++i)
        {
            temp=temp+a;
            if(temp.find(b)!=(-1)) return i+1;
        }

        return -1;
    }
};