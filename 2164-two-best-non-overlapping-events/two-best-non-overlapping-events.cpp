class Solution
{
    public:
        int maxTwoEvents(vector<vector < int>> &events)
        {
            int n = events.size();
            vector<int> suffix(n, 0);
            sort(events.begin(), events.end());
            suffix[n - 1] = events[n - 1][2];
            for (int i = n - 2; i >= 0; i--)
            {
                suffix[i] = max(suffix[i + 1], events[i][2]);
            }
            int ans = 0;
            for (int i = 0; i < n; i++)
            {
                int s = events[i][0];
                int e = events[i][1];
                int l = i + 1, r = n - 1;
                while (l <= r)
                {
                    int mid = (l + r) / 2;
                    if (events[mid][0] > e)
                    {
                        ans = max(ans, events[i][2] + suffix[mid]);
                        r = mid - 1;
                    }
                    else
                    {
                        l = mid + 1;
                    }
                }
                ans = max(ans, events[i][2]);
            }
            return ans;
        }
};