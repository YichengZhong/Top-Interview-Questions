class Solution {
public:
    int maxCount;
    int removeStones(vector<vector<int>>& stones) {
        //菜鸡回溯
        maxCount=0;
        vector<int>line_index;
        line_index.clear();

        vector<int>row_index;
        row_index.clear();

        helpDFS(stones,0,line_index,row_index,0);

        return stones.size()-maxCount;
    }

    void helpDFS(vector<vector<int>>& stones,int count,vector<int>&line_index,vector<int>&row_index ,int index)
    {
        maxCount=max(maxCount,count);
        if(index>=stones.size()) return;

        for(int i=index;i<stones.size();++i)
        {
            int line_temp=stones[i][0];
            int rank_temp=stones[i][1];

            if(find(line_index.begin(), line_index.end(), line_temp)==line_index.end() && find(row_index.begin(), row_index.end(), rank_temp)==row_index.end())
            {
                line_index.push_back(line_temp);
                row_index.push_back(rank_temp);

                helpDFS(stones,count+1,line_index,row_index,index+1);

                line_index.pop_back();
                row_index.pop_back();
            }
        }
    }
};