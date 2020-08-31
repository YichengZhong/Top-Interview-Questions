class Solution {
public:
    int maxInter;
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        maxInter=0;
        vector<vector<int>> temp;
        help(0,temp,intervals);

        int out=intervals.size()-maxInter;
        return out;
    }

    void help(int index,vector<vector<int>> temp,vector<vector<int>>& intervals)
    {
        if(temp.size()>0)
        {
            maxInter=maxInter>temp.size()?maxInter:temp.size();
        }

        for(int i=index;i<intervals.size();++i)
        {
            //判断加入之后是否重叠
            if(checkIfLap(temp,intervals[i]))
            {
                temp.push_back(intervals[i]);
                help(i+1,temp,intervals);
                temp.pop_back();
            }
        }

       
    }

    bool checkIfLap(vector<vector<int>> temp,vector<int> temp_item)
    {
        if(temp.size()==0)
        {
            return true;
        }

        for(int i=0;i<temp.size();++i)
        {
            if((temp[i][1]<=temp_item[0]) || (temp_item[1]<=temp[i][0]))
            {
                continue;
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};