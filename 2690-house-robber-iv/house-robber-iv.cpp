class Solution
{

    bool solve(vector<int> &nums, int mid, int k)
    {
        int cnt = 0, i = 0;
        while (i < nums.size())
        {
            if (nums[i] <= mid)
            {
                cnt++;
                i++;
            }
            i++;
        }
        return cnt >= k;
    }
    public:
        int minCapability(vector<int> &nums, int k)
        {
            int l = 0, r = 1e9 + 1;
            int ans = 0;
            while (l <= r)
            {
                int mid = (l + r) / 2;
                if (solve(nums, mid, k))
                {
                    ans = mid;
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            return ans;
        }
};