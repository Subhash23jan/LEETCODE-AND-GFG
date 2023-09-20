class Solution
{
    public:
        int minOperations(vector<int> &nums, int x)
        {
            int sum = 0;
            for (auto it: nums)
                sum += it;
            if(sum<x)
            return -1;
            int target = sum - x;
            sum = 0;
            int ans = INT_MIN, j = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                sum += nums[i];
                while (j<nums.size() && sum > target)
                {
                    sum -= nums[j];
                    j++;
                }
                if (sum == target)
                    ans = max(ans, i - j+1);
            };
            return ans == INT_MIN?-1:(nums.size()-ans);
        }
};