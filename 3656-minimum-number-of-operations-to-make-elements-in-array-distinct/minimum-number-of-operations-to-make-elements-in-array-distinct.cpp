class Solution
{
    public:
        int minimumOperations(vector<int> &nums)
        {
            int n = nums.size();
            unordered_map<int, int> mp;
            for (auto it: nums)
            {
                mp[it]++;
            }
            int j = 0, cnt = 0;
            for (int i = n - 1; i >= 0; i--)
            {
                if (mp[nums[i]] > 1)
                {
                    while (mp[nums[i]] > 1)
                    {
                        int k = j + 3;
                        while (j < n && j < k)
                        {
                            mp[nums[j]]--;
                            j++;
                        }
                        cnt++;
                    }
                }
                if (i <= j) return cnt;
            }
            return cnt;
        }
};