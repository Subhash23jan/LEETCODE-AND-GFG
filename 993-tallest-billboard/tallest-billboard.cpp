class Solution
{
    int dp[21][10001];
    int solve(int i, const vector<int> &rods, int diff)
    {
        if (i == rods.size()) return diff == 0 ? 0 : INT_MIN;
        if(dp[i][5000+diff]!=-1) return dp[i][5000+diff];
        int left = rods[i] + solve(i + 1, rods, diff + rods[i]);
        int right = solve(i + 1, rods, diff - rods[i]);
        int skip = solve(i + 1, rods, diff);
        return dp[i][5000+diff]=max({ left,
            right,
            skip });
    }
    public:
        int tallestBillboard(vector<int> &rods)
        {
            memset(dp,-1,sizeof(dp));
            return solve(0, rods, 0);
        }
};