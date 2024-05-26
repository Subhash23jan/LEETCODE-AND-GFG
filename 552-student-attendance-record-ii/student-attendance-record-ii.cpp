class Solution {
    int dp[100001][3][4];
    int mod = 1e9 + 7;

    int solve(int n, int A, int L) {
        if(A==2 || L==3){
            return false;
        }
        if (n <= 0)
            return 1;
        if (dp[n][A][L] != -1)
            return dp[n][A][L];

        long long ans = 0;
        ans = (ans + solve(n - 1, A, 0)) % mod;

        ans = (ans + solve(n - 1, A + 1, 0)) % mod;

        ans = (ans + solve(n - 1, A, L + 1)) % mod;

        return dp[n][A][L] = ans;
    }

public:
    int checkRecord(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n, 0, 0);
    }
};
