class Solution {
public:
    string p;
    bool paix(string& a,string& b){
        int i=0;
        while(i<a.length()&&i<b.length()&&a[i]==b[i]) ++i;
        if(i==a.length()||i==b.length()) return a.length()<=b.length();
        return p.find(a[i])<=p.find(b[i]);    
    }

    bool isAlienSorted(vector<string>& words, string order) {
        
        p=order;
        int len=words.size();
        for(int i=1;i<len;++i)
        {
            if(!paix(words[i-1],words[i])) return false;
        }
        
        return true;
    }
};