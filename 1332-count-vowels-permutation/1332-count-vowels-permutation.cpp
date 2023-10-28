class Solution
{
    int mod = 1e9 + 7;
    vector<vector<int>>dp;
    map<char,int>mp={{'a',0},{'e',1},{'i',2},{'o',3},{'u',4}};
    
    int solve(int prevChar, int n)
    {
        if (n == 0)
            return 1;
        int ans = 0;
        int index=mp[prevChar];
        if(dp[index][n]!=-1)
         return dp[index][n]%mod;
        if (prevChar == 'a')
        {
            return dp[index][n]=(solve('e', n - 1) % mod);
        }
        if (prevChar == 'e')
        {
            ans += solve('a', n - 1) % mod;
            ans += solve('i', n - 1) % mod;
            return dp[index][n]=(ans)%mod;
        }
        if (prevChar == 'o')
        {
            ans += solve('i', n - 1) % mod;
            ans += solve('u', n - 1) % mod;
            return dp[index][n]=(ans)%mod;
        }
        if (prevChar == 'u')
        {
            ans += solve('a', n - 1) % mod;
            return dp[index][n]=(ans)%mod;
        }
        ans =(ans+ (solve('a', n - 1) % mod)%mod);
        ans = (ans+(solve('e', n - 1) % mod))%mod;
        ans =(ans+(solve('o', n - 1) % mod))%mod;
        ans = (ans+(solve('u', n - 1) % mod)%mod);
        return dp[index][n]=(ans)%mod;
    }
    public:
    int countVowelPermutation(int n)
    {
        int ans = 0;
        dp.resize(6,vector<int>(n+1,-1));
        char arr[5] = { 'a',
            'e',
            'i',
            'o',
            'u' };
        for (int i = 0; i < 5; i++)
        {
            ans =(ans+ (solve(arr[i], n - 1) % mod))%mod;
        }
        return ans%mod;
    }
};