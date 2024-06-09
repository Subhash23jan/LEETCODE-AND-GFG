class Solution
{
    int dp[71][71][71];
    int solve(int i, int j, int k, vector<vector < int>> &grid)
    {
        if (i == grid.size() || j == grid[0].size() || j>=k || k < 0 || j < 0 || k == grid[0].size()) return 0;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        int val = grid[i][j] + grid[i][k];
        int ans = 0;
        for (int r = -1; r <= 1; r++)
        {
            for (int c = -1; c <= 1; c++)
            {
                
                    ans = max(ans, solve(i + 1, j + r, k + c, grid));
                
            }
        }
        return dp[i][j][k]= ans + val;
    }
    public:
        int cherryPickup(vector<vector < int>> &grid)
        {
            int n = grid.size();
            int m = grid[0].size();
            memset(dp,-1,sizeof(dp));
            return solve(0, 0, m - 1, grid);
        }
};