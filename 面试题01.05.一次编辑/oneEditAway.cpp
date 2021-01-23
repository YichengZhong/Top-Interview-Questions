class Solution {
public:
    bool oneEditAway(string first, string second) {
        string longstr=first.size()>=second.size()?first:second;
        string shortstr=first.size()<second.size()?first:second;

        if((longstr.size()-shortstr.size())>=2) return false;

        if(first.size()==second.size())
        {
            return jugeSameSize(first, second);
        }
        
        return jugeNotSameSize(longstr,shortstr);
    }

    bool jugeSameSize(string first, string second)
    {
        bool flag=false;
        for(int i=0;i<first.size();++i)
        {
            if(first[i]==second[i]) continue;
            else
            {
                if(flag==false)
                {
                    flag=true;
                    continue;
                }
                else return false;
            }
        }

        return true;
    }

    bool jugeNotSameSize(string longstr,string shortstr)
    {
        bool flag=false;
        for(int i=0,j=0;i<shortstr.size()&& j<longstr.size();)
        {
            if(longstr[j]==shortstr[i]) 
            {
                i++;
                j++;
                continue;
            }
            else
            {
                if(flag==false && longstr[j+1]==shortstr[i])
                {
                    flag=true;
                    j++;
                    continue;
                }
                else return false;
            }
        }

        return true;
    }
};