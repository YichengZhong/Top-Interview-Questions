class Solution {
public:
    int maxInter;
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        //类似于区间重合问题
        //以最短的数组为基准
        vector<int>v_long;
        vector<int>v_short;
        maxInter=0;

        v_long=B;
        v_short=A;

        vector<vector<int>>line_index;

        for(int i=0;i<v_short.size();++i)
        {
            for(int j=0;j<v_long.size();++j)
            {
                if(v_long[j]==v_short[i])
                {
                    vector<int>temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    line_index.push_back(temp);
                }
            }
        }

        //直接转换区间问题
        vector<vector<int>> temp;
        help(0,temp,line_index);
        
        return maxInter;
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
            //在左边
            if(temp[i][0]<temp_item[0] && temp[i][1]<temp_item[1])
            {
                continue;
            }
            else if(temp[i][0]>temp_item[0] && temp[i][1]>temp_item[1])//在右边
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