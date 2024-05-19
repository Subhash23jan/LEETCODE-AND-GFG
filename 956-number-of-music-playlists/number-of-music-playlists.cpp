class Solution {
    int mod=1e9+7;
    int dp[101][101];
    long long solve(int n, int goal, int k)
    {
        if(n==0 && goal==0) return 1;
        if(n==0 || goal==0) return 0;
        if(dp[goal][n]!=-1) return dp[goal][n];
        int pick=(solve(n-1,goal-1,k)*n) %mod;
        int nopick=(solve(n,goal-1,k)*max(n-k,0)) %mod;
        return dp[goal][n]=(pick+nopick)%mod;
    }
public:
    int numMusicPlaylists(int n, int goal, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(n,goal,k)%mod;
    }
};