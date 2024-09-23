class Solution
{
    int dp[51];
    int solve(int index, set<string> st, string s)
    {
        if (index == s.size())
            return 0;
        string temp = "";
        if (dp[index] != -1)
            return dp[index];
        int ans = 1+solve(index+1,st,s);
        for (int j = index; j < s.size(); j++)
        {
            temp = s.substr(index, j - index + 1);
            if (st.find(temp) != st.end())
            {
                ans = min(ans, solve(index + temp.size(), st, s));
            }
        }
        return dp[index] = ans;
    }
    public:
        int minExtraChar(string s, vector<string> &dictionary)
        {
            set<string> st;
            memset(dp, -1, sizeof(dp));
            for (auto it: dictionary)
                st.insert(it);
            return solve(0, st, s);
        }
};