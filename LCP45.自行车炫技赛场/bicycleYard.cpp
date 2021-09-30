class Solution {
public:
    int vis[110][110][105],ab[4][2] = {0,-1,1,0,0,1,-1,0},n,m;
    void dfs(int x,int y,int v, vector<vector<int>>& t, vector<vector<int>>& o){
        for (int i = 0; i < 4; i ++){
            int xx = x + ab[i][0], yy = y + ab[i][1];
            if (xx >= 0 && xx < n && yy >= 0 && yy < m){
                int vv = t[x][y] - t[xx][yy] - o[xx][yy] + v;
                if (vv >= 1&&!vis[xx][yy][vv]){
                    vis[xx][yy][vv] = 1;
                    dfs(xx,yy,vv,t,o);
                }
            }
        }
    }
    vector<vector<int>> bicycleYard(vector<int>& p, vector<vector<int>>& t, vector<vector<int>>& o) {
        vector<vector<int>> res;
        n = t.size(),m = t[0].size();
        vis[p[0]][p[1]][1] = 1;
        dfs(p[0],p[1],1,t,o);
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < m; j ++){
                if (vis[i][j][1]&&!(i == p[0] && j == p[1])){
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
};