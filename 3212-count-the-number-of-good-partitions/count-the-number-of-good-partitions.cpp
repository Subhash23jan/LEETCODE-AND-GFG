class Solution
{
    int mod = 1e9 + 7;
    long long solve(long long b, long long p)
    {
        long long res = 1;
        while (p > 0)
        {
            if (p & 1)
            {
                res = (res *b) % mod;
            }
            b = (b *b) % mod;
            p /= 2;
        }
        return res;
    }

    public:
        int numberOfGoodPartitions(vector<int> &nums)
        {
            int cnt = 0;
            int i = 0;
            int mod = 1e9 + 7;
            int n = nums.size();
            map<int, int> mp;
            int maxInd = -1;
            for (int i = 0; i < n; i++)
            {
                mp[nums[i]] = -1;
            }
            for (int i = 0; i < n; i++)
            {
                mp[nums[i]] = max(mp[nums[i]], i);
            }

            while (i < n)
            {
                maxInd = max(maxInd, mp[nums[i]]);
                if (maxInd == i)
                    cnt++;
                i++;
            }
            cnt--;
            return solve(2, cnt);
        }
};