class Solution {
    int dp[501][501];
public:
    int minInsertions(string s) {
        int i=0,n=s.size();
        memset(dp,0,sizeof(dp));
        string str(s.rbegin(),s.rend());
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==str[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                     dp[i][j]=max( dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return n-dp[n][n];
    }
};