class Solution
{
    public:
        int maxFrequency(vector<int> &nums, int k)
        {
            vector<int> dp(nums.size(), 0);
            sort(nums.begin(), nums.end());
            int ans=0, l = 0, r = 0;
            long long sum=0;
            while (r < nums.size())
            {
                sum += nums[r];
                while ((sum + k) / (r - l + 1) < nums[r])
                {
                    sum -= nums[l];
                    l++;
                }
                ans = max(ans, r - l + 1);
                r++;
            }
            return ans;
        }
};