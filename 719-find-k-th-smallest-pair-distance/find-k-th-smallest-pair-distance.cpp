class Solution
{
    bool solve(const vector<int> &nums, int mid, int k)
    {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int index = upper_bound(nums.begin(), nums.end(), mid + nums[i]) - nums.begin();
            cnt += (index - i - 1);
        }
        return cnt >= k;
    }
    public:
        int smallestDistancePair(vector<int> &nums, int k)
        {
            int ans = 0;
            sort(nums.begin(), nums.end());
            int l = 0, r = *max_element(nums.begin(), nums.end());
            while (l < r)
            {
                int mid = (l + r) / 2;
                if (solve(nums, mid, k))
                {
                    ans = mid;
                    r = mid;
                }
                else
                {
                    l = mid + 1;
                }
            }
            return ans;
        }
};