class Solution
{
    vector<vector<vector< long long>>> dp;

    long long solve(int i, int j, int rem, const vector<int> &robot, const vector<vector < int>> &factory)
    {
        if (i == robot.size()) return 0;
        if (j == factory.size()) return LONG_LONG_MAX;

        if (dp[i][j][rem] != -1) return dp[i][j][rem];

        long long skip = (j + 1 < factory.size()) ? solve(i, j + 1, factory[j + 1][1], robot, factory) : LONG_LONG_MAX;
        long long noSkip = LONG_LONG_MAX;

        if (rem > 0)
        {
            long long dist = abs(robot[i] - factory[j][0]);
            long long nextDist = solve(i + 1, j, rem - 1, robot, factory);
            if (nextDist != LONG_LONG_MAX) noSkip = dist + nextDist;
        }

        return dp[i][j][rem] = min(skip, noSkip);
    }

    public:
        long long minimumTotalDistance(vector<int> &robot, vector<vector< int>> &factory)
        {
            sort(robot.begin(), robot.end());
            sort(factory.begin(), factory.end());

            dp.assign(robot.size(), vector<vector < long long>> (factory.size(), vector < long long > (robot.size() + 1, -1)));
            return solve(0, 0, factory[0][1], robot, factory);
        }
};