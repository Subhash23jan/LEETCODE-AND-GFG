class Solution
{
    int dp[101][101];
    bool solve(int start, int end, vector<int> adj[])
    {
        if (start == end) return true;
        if (dp[start][end] != -1) return dp[start][end];
        bool ans = false;
        for (auto it: adj[start])
        {
            ans |= solve(it, end, adj);
        }
        return dp[start][end] = ans;
    }
    public:
        vector<bool> checkIfPrerequisite(int n, vector<vector < int>> &prerequisites, vector< vector< int>> &queries)
        {
            vector<bool> ans;
            vector<int> adj[n];
            for (auto it: prerequisites)
            {
                adj[it[0]].push_back(it[1]);
            }
            memset(dp, -1, sizeof(dp));
            for (auto it: queries)
            {
                bool res = solve(it[0], it[1], adj);
                ans.push_back(res);
            }
            return ans;
        }
};