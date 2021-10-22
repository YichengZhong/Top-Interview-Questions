class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxConut=0;

        for(int i=0;i<grid.size();++i)
        {
            for(int j=0;j<grid[0].size();++j)
            {
                if(grid[i][j]==1)
                {
                    int tempcount=GetArea(i,j,grid);
                    maxConut=max(maxConut,tempcount);
                }
            }
        }

        return maxConut;
    }

    int GetArea(int index_i,int index_j,vector<vector<int>>& grid)
    {
        int count=0;
        queue<vector<int>>node_queue;

        node_queue.push({index_i,index_j});

        while(!node_queue.empty())
        {
            int size=node_queue.size();

            for(int i=0;i<size;++i)
            {
                vector<int>topnode=node_queue.front();
                node_queue.pop();
                int topindex_x=topnode[0];
                int topindex_y=topnode[1];

                if(grid[topindex_x][topindex_y]==1)
                {
                    count++;
                    grid[topindex_x][topindex_y]=0;
                }

                //上下左右
                if(topindex_x-1>=0 && grid[topindex_x-1][topindex_y]==1)
                {
                    node_queue.push({topindex_x-1,topindex_y});
                }

                if(topindex_x+1<grid.size() && grid[topindex_x+1][topindex_y]==1)
                {
                    node_queue.push({topindex_x+1,topindex_y});
                }

                if(topindex_y-1>=0 && grid[topindex_x][topindex_y-1]==1)
                {
                    node_queue.push({topindex_x,topindex_y-1});
                }

                if(topindex_y+1<grid[0].size() && grid[topindex_x][topindex_y+1]==1)
                {
                    node_queue.push({topindex_x,topindex_y+1});
                }
            }
        }

        return count;
    }
};