class Solution
{
    int solve(int i, int currVal, vector<int> nums, int need)
    {
        if (i == nums.size()) return currVal == need;
        return solve(i + 1, currVal | nums[i], nums, need) + solve(i + 1, currVal, nums, need);
    }
    public:
        int countMaxOrSubsets(vector<int> &nums)
        {
            int val = 0;
            for (auto it: nums)
            {
                val |= it;
            }
            return solve(0, 0, nums, val);
        }
};