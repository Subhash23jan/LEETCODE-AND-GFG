class Solution
{
    private:
        vector<int> dp;
    int solve(int i, vector<int> &prefix)
    {
        if (i == prefix.size() - 1)
            return prefix[i];

        if (dp[i] != INT_MIN)
            return dp[i];

        int take = prefix[i] - solve(i + 1, prefix);
        int notake = solve(i + 1, prefix);
        return dp[i] = max(take, notake);
    }
    public:
        int stoneGameVIII(vector<int> &stones)
        {
            int n = stones.size();
            dp.resize(n + 1, INT_MIN);
            vector<int> prefix(n, 0);
            prefix[0] = stones[0];
            for (int i = 1; i < n; i++)
                prefix[i] += prefix[i - 1] + stones[i];
            return solve(1, prefix);
        }
};