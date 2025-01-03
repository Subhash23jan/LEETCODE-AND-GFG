class Solution
{
    public:
        int waysToSplitArray(vector<int> &nums)
        {
            long long left = 0, right = 0;
            for (auto it: nums)
            {
                right += it;
            }
            int ans = 0;
            for (int i = 0; i < nums.size() - 1; i++)
            {
                left += nums[i];
                right -= nums[i];
                if (left >= right) ans++;
            }
            return ans;
        }
};