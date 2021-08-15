class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        memo = vector<vector<vector<int>>> (m, vector<vector<int>>(n, vector<int>(N + 1, -1)));
        return dfs(m, n, N, i, j);
    }
    
    long dfs(int m, int n, int N, int i, int j) {
        if (i < 0 || j < 0 || i >= m || j >= n) {
            return 1;
        }

        if (memo[i][j][N] != -1) {
            return memo[i][j][N];
        }

        if (N == 0) {
            return 0; // after N step still within range
        }

        long res = 0;
        for (const auto& dir : dirs) {
            auto ni = i + dir[0];
            auto nj = j + dir[1];
            res += dfs(m, n, N - 1 , ni, nj);
            res %= MOD;
        }

        memo[i][j][N] = res;
        return memo[i][j][N];
    }

private:
    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    vector<vector<vector<int>>> memo;
    const int MOD = 1000000007;
};