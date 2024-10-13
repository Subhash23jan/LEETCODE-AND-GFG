class Solution
{
    public:
        vector<int> smallestRange(vector<vector < int>> &nums)
        {
            priority_queue<pair<int, pair<int, int>>> pq;
            int n = nums.size();
            int mx = INT_MIN;
            for (int i = 0; i < n; i++)
            {
                pq.push({ -nums[i][0],
                    {
                        i,
                        0
                    } });
                mx = max(mx, nums[i][0]);
            }
            int ans = INT_MAX;
            vector<int> res(2, 0);
            while (true)
            {
                int range = mx + pq.top().first;
                int r = pq.top().second.first;
                int c = pq.top().second.second;
                if (ans > range)
                {
                    ans = range;
                    res[0] = -pq.top().first;
                    res[1] = mx;
                }
                pq.pop();
                if (c < nums[r].size() - 1)
                {
                    pq.push({ -nums[r][c + 1],
                        {
                            r,
                            c + 1
                        } });
                    mx = max(mx, nums[r][c + 1]);
                }
                if (pq.size() < n)
                {
                    break;
                }
            }
            return res;
        }
};