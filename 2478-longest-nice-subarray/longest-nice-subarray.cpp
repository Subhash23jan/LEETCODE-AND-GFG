class Solution
{
    public:
        int longestNiceSubarray(vector<int> &nums)
        {
            int n = nums.size();
            vector<int> dp(32, 0);
            int l = 0, r = 0, cnt = 0, ans = 1;
            while (r < n)
            {
                for (int i = 0; i < 32; i++)
                {
                    if (nums[r] &(1 << i))
                    {
                        dp[i]++;
                        if (dp[i] > 1) cnt++;
                    }
                }
                while (l <= r && cnt >= 1)
                {
                    for (int i = 0; i < 32; i++)
                    {
                        if (nums[l] &(1 << i))
                        {
                            dp[i]--;
                            if (dp[i] >= 1) cnt--;
                        }
                    }
                    l++;
                }
                ans = max(ans, r - l + 1);
                r++;
            }
            return ans;
        }
};