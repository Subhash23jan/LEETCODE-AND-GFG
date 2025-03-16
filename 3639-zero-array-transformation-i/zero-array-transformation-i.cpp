class Solution
{
    public:
        bool isZeroArray(vector<int> &nums, vector<vector<int>> &queries)
        {
            int n = nums.size();
            vector<int> dp(n + 1, 0);

            for (auto it: queries)
            {
                dp[it[0]] += 1;
                if (it[1] + 1 < n) dp[it[1] + 1] -= 1;
            }

            int preSum = 0;
            for (int i = 0; i < n; i++)
            {
                preSum += dp[i];
                if (preSum < nums[i]) return false;
            }

            return true;
        }
};
