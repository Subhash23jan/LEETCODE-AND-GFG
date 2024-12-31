class Solution
{
    vector<int> dp;
    int solve(int ind, vector<int> &days, vector<int> &costs)
    {
        if (ind == days.size()) return 0;
        if (dp[ind] != -1) return dp[ind];
        int ans = costs[0] + solve(ind + 1, days, costs);
        auto it1 = upper_bound(days.begin(), days.end(), days[ind] + 6) - days.begin();
        ans = min(ans, costs[1] + solve(it1, days, costs));
        auto it2 = upper_bound(days.begin(), days.end(), days[ind] + 29) - days.begin();
        ans = min(ans, costs[2] + solve(it2, days, costs));
        return dp[ind] = ans;
    }

    public:
        int mincostTickets(vector<int> &days, vector<int> &costs)
        {
            int n = days.size();
            dp.resize(n, -1);
            return solve(0, days, costs);
        }
};