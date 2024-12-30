class Solution
{
    public:
        int countGoodStrings(int low, int high, int zero, int one)
        {
            int mod = 1e9 + 7;
            vector<int> dp(high + 1, 0);
            dp[0] = 1;	
            for (int len = 1; len <= high; ++len)
            {
                if (len >= zero)
                    dp[len] = (dp[len] + dp[len - zero]) % mod;
                if (len >= one)
                    dp[len] = (dp[len] + dp[len - one]) % mod;
            }

            int ans = 0;
            for (int len = low; len <= high; ++len)
            {
                ans = (ans + dp[len]) % mod;	
            }

            return ans;
        }
};