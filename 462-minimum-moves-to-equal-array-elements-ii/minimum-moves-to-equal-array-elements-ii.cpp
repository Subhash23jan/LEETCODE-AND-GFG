class Solution
{
    long long solve(int mid, const vector<int> &nums)
    {
        long long cost = 0;
        for (auto it: nums)
        {
            cost += abs(it - mid);
        }
        return cost;
    }
    public:
        int minMoves2(vector<int> &nums)
        {
            int ans = INT_MAX;
            int l = *min_element(nums.begin(), nums.end()), r = *max_element(nums.begin(), nums.end());

            while (l <= r)
            {
                int mid = (l + r) / 2;
                long long cost1 = solve(mid, nums);
                long long cost2 = solve(mid + 1, nums);
                if (cost1 < cost2)
                {
                    ans = cost1;
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            return ans;
        }
};