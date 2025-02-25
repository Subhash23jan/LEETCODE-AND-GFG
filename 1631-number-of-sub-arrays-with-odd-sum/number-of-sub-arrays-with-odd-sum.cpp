class Solution
{
    public:
        int numOfSubarrays(vector<int> &arr)
        {
            const int MOD = 1e9 + 7;
            unordered_map<int, int> mp;
            int sum = 0, ans = 0;
            mp[0] = 1;
            for (auto it: arr)
            {
                sum += it;
                sum %= 2;
                ans = (ans + mp[1 - sum]) % MOD;
                mp[sum]++;
            }
            return ans;
        }
};