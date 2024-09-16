class Solution
{
    public:
        long long largestSquareArea(vector<vector < int>> &bottomLeft, vector< vector< int>> &topRight)
        {
            long long ans = 0;
            int n = bottomLeft.size();
            for (int i = 0; i < n; i++)
            {
                int lx1 = bottomLeft[i][0], lY1 = bottomLeft[i][1];
                int rx1 = topRight[i][0], rY1 = topRight[i][1];
                for (int j = i + 1; j < n; j++)
                {
                    int lx2 = bottomLeft[j][0], lY2 = bottomLeft[j][1];
                    int rx2 = topRight[j][0], rY2 = topRight[j][1];
                    int x = min(rx1, rx2) - max(lx1, lx2);
                    int y = min(rY1, rY2) - max(lY1, lY2);
                    if (x > 0 && y > 0)
                    {
                        long long mn = min(x, y);
                        long long area=mn*mn;
                        ans = max(ans, area);
                    }
                }
            }
            return ans;
        }
};