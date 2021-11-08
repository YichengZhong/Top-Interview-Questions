class Solution {
public:
    vector<int>landare;
    vector<int> pondSizes(vector<vector<int>>& land) {
        //BFS
        landare.clear();

        for(int i=0;i<land.size();++i)
        {
            for(int j=0;j<land[0].size();++j)
            {
                if(land[i][j]==0)
                {
                    int count=getLandArea(land,i,j);
                    landare.push_back(count);
                }
            }
        }

        sort(landare.begin(),landare.end());

        return landare;
    }

    int getLandArea(vector<vector<int>>& land,int index_x,int index_y)
    {
        queue<int>index_x_list;
        queue<int>index_y_list;

        index_x_list.push(index_x);
        index_y_list.push(index_y);
        int count=0;

        while(!index_x_list.empty())
        {
            int size=index_x_list.size();
            for(int i=0;i<size;++i)
            {
                int x=index_x_list.front();
                index_x_list.pop();
                int y=index_y_list.front();
                index_y_list.pop();

                if(land[x][y]==0)
                {
                    count++;
                    land[x][y]=(-1);
                }

                //上下左右和对角线
                //向上
                if((x+1)<land.size() && land[x+1][y]==0)
                {
                    index_x_list.push(x+1);
                    index_y_list.push(y);
                }

                //向下
                if((x-1)>=0 && land[x-1][y]==0)
                {
                    index_x_list.push(x-1);
                    index_y_list.push(y);
                }

                //向左
                if((y-1)>=0 && land[x][y-1]==0)
                {
                    index_x_list.push(x);
                    index_y_list.push(y-1);
                }

                //向右
                if((y+1)<land[0].size() && land[x][y+1]==0)
                {
                    index_x_list.push(x);
                    index_y_list.push(y+1);
                }

                //右上
                if((x-1)>=0 && (y+1)<land[0].size() && land[x-1][y+1]==0)
                {
                    index_x_list.push(x-1);
                    index_y_list.push(y+1);
                }

                //右下
                if((x+1)<land.size() && (y+1)<land[0].size() && land[x+1][y+1]==0)
                {
                    index_x_list.push(x+1);
                    index_y_list.push(y+1);
                }

                //左上
                if((x-1)>=0 && (y-1)>=0 && land[x-1][y-1]==0)
                {
                    index_x_list.push(x-1);
                    index_y_list.push(y-1);
                }

                //左下
                if((x+1)<land.size() && (y-1)>=0 && land[x+1][y-1]==0)
                {
                    index_x_list.push(x+1);
                    index_y_list.push(y-1);
                }

            }
        }
        
        return count;
    }
};