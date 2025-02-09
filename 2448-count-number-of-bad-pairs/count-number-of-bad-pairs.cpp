class Solution
{
    public:
        long long countBadPairs(vector<int> &nums)
        {
            unordered_map<int, long long > mp;
            long long n = nums.size();
            long long ans = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                ans += (i) - mp[nums[i] - i];
                mp[nums[i] - i]++;
            }
            return ans;
        }
};