class Solution
{
    int dp[1001][1001];
    int solve(int i, int j, vector<vector < int>> &grid)
    {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        if (dp[i][j] != -1) return dp[i][j];
        if (i + 1 < n && j + 1 < m && grid[i][j] < grid[i + 1][j + 1])
        {
            ans = max(ans, 1 + solve(i + 1, j + 1, grid));
        }
        if (i - 1 >= 0 && j + 1 < m && grid[i][j] < grid[i - 1][j + 1])
        {
            ans = max(ans, 1 + solve(i - 1, j + 1, grid));
        }
        if (j + 1 < m && grid[i][j] < grid[i][j + 1])
        {
            ans = max(ans, 1 + solve(i, j + 1, grid));
        }
        return dp[i][j] = ans;
    }
    public:
        int maxMoves(vector<vector < int>> &grid)
        {
            int ans = 0;
            memset(dp, -1, sizeof(dp));
            for (int i = 0; i < grid.size(); i++)
            {
                ans = max(ans, solve(i, 0, grid));
            }
            return ans;
        }
};