class Solution
{
    bool isPossible(vector<int> nums, int mid, long long k)
    {
        long long cnt = 0;
        for (auto it: nums)
        {
            cnt += 1LL*(it / mid);
        }
        return cnt >= k;
    }
    public:
        int maximumCandies(vector<int> &candies, long long k)
        {
            long long ans = 0;
            int l = 0, r = 1e8;
            while (l <= r)
            {
                int mid = (l + r) / 2;
                if (mid == 0 || isPossible(candies, mid, k))
                {
                    ans = mid;
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
            return ans;
        }
};