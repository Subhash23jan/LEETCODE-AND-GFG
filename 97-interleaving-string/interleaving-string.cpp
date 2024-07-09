class Solution
{
    int dp[101][101][200];
    bool solve(int i, int j, int k, string s1, string s2, string s3)
    {
        if (k == s3.size()) return i == s1.size() && j == s2.size();
        if (dp[i][j][k] != -1) return dp[i][j][k];
        bool ans = false;
        if (i < s1.size() && s1[i] == s3[k])
        {
            ans |= solve(i + 1, j, k + 1, s1, s2, s3);
        }
        if (j < s2.size() && s2[j] == s3[k])
        {
            ans |= solve(i, j + 1, k + 1, s1, s2, s3);
        }
        return dp[i][j][k] = ans;
    }
    public:
        bool isInterleave(string s1, string s2, string s3)
        {
            memset(dp, -1, sizeof(dp));
            return solve(0, 0, 0, s1, s2, s3);
        }
};