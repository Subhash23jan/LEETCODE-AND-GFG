class Solution
{
    public:
        vector<bool> isArraySpecial(vector<int> &nums, vector<vector< int>> &queries)
        {
            int n = nums.size();
            vector<int> left(n, 0), right(n, 0);

            for (int i = 1; i < n; i++)
            {
                left[i] = left[i - 1] + (nums[i] % 2 == nums[i - 1] % 2);
            }

            vector<bool> result;
            for (const auto &q: queries)
            {
                int l = q[0], r = q[1];
                int diff = left[l] - left[r];
                result.push_back(diff == 0);
            }

            return result;
        }
};