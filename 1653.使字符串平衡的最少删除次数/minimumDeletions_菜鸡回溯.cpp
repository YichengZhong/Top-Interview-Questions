class Solution {
public:
    int maxlen;
    int minimumDeletions(string s) {
        maxlen=0;
        helpDFS(s,"",0);

        return s.size()-maxlen;
    }

    void helpDFS(string s,string temp,int index)
    {
        if(index>=s.size())
        {
            maxlen=temp.size()>maxlen?temp.size():maxlen;
            return ;
        }

        for(int i=index;i<s.size();++i)
        {
            string temp2=temp+s[i];
            string temp3=temp2;
            sort(temp2.begin(),temp2.end());
            if(temp2==temp3)
            {
                helpDFS(s,temp+s[i],i+1);
            }
        }
    }
};