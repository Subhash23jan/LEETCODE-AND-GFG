class Solution
{
    public:
        int minSubArrayLen(int target, vector<int> &nums)
        {
            int ans = 0, n = nums.size();
            ans = n+1;
            int l = 0, r = 0, sum = 0;
            while (r < n)
            {
                sum += nums[r];
                r++;
                while (l < r && sum - nums[l] >= target)
                {
                    sum -= nums[l];
                    l++;
                }
                if (sum >= target)
                {
                    ans = min(ans, r - l);
                }
            }
            return ans==n+1?0:ans;
        }
};