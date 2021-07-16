class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
       
        int M=grid.size(),N=grid[0].size();
        if(grid[0][0]==1||grid[M-1][N-1]==1)return -1;
        queue<vector<int>>que;
        que.push({0,0});
         vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
        int res=1;
        while(!que.empty()){
            int size=que.size();
            for(int i=0;i<size;++i){
                auto cur=que.front();
                int x=cur[0];
                int y=cur[1];
                que.pop();
                if(x==M-1&&y==N-1)return res;
                for(vector<int>& d:dir){
                    int nx=x+d[0];
                    int ny=y+d[1];
                    if(nx<0||nx>=M||ny<0||ny>=N||grid[nx][ny]==1)continue;
                    
                    grid[nx][ny]=1;
                    que.push({nx,ny});
                }
            }
            res++;
        }
        return -1;

    }
};