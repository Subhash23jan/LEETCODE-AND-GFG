class Solution
{
    public:
        long long maxSubarraySum(vector<int> &nums, int k)
        {
            unordered_map<int, long long > mp;
            mp[0] = 0;
            long long currSum = 0, ans = LONG_LONG_MIN;
            for (int i = 0; i < nums.size(); i++)
            {
                currSum += nums[i];
                int mod = (i + 1) % k;
                if (mp.count(mod))
                    ans = max(ans, currSum - mp[mod]);
                if (!mp.count(mod))
                    mp[mod] = currSum;
                else
                    mp[mod] = min(mp[mod], currSum);
            }
            return ans;
        }
};