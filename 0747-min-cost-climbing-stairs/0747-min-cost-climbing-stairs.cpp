class Solution
{
    int dp[1001];
    int solve(int index, vector<int> &cost)
    {
        if (index >= cost.size())
            return 0;
        if (dp[index] != -1)
            return dp[index];
        return dp[index]=cost[index] + min(solve(index + 1, cost), solve(index + 2, cost));
    }
    public:
        int minCostClimbingStairs(vector<int> &cost)
        {
            memset(dp, -1, sizeof(dp));
            return min(solve(0, cost), solve(1, cost));
        }
};