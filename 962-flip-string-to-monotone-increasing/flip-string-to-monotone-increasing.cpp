class Solution
{
    public:
        int minFlipsMonoIncr(string s)
        {
            int n = s.size();
            int ans = n + 1,cnt=0;
            vector<int> dp(n+1, 0);
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '1')
                {
                    cnt++;
                }
                dp[i+1]=cnt;
            }
            ans = cnt;
            cnt=0;
            for (int i = n - 1; i >= 0; i--)
            {
                if (s[i] == '0') cnt++;
                ans = min(ans, dp[i] + cnt);
                
            }
            ans=min(ans,cnt);
            return ans;
        }
};