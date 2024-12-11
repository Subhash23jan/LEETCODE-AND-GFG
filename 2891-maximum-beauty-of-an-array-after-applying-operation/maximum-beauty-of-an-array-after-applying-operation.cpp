class Solution
{
    public:
        int maximumBeauty(vector<int> &nums, int k)
        {
            sort(nums.begin(), nums.end());
            int n = nums.size(), ans = 1;
            for (int i = 0; i < n; i++)
            {
                int low = lower_bound(nums.begin(), nums.end(), nums[i] - 2 *k) - nums.begin();
                ans = max(ans, i - low + 1);
            }
            return ans;
        }
};