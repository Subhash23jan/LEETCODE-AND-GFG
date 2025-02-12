class Solution
{
    public:
        int maximumSum(vector<int> &nums)
        {
            unordered_map<int, int> mp;
            int ans = -1;
            for (auto it: nums)
            {
                int num = it, sum = 0;
                while (num)
                {
                    sum += num % 10;
                    num /= 10;
                }
                if (mp.count(sum))
                {
                    ans = max(ans, mp[sum] + it);
                }
                mp[sum] = max(mp[sum], it);
            }
            return ans;
        }
};