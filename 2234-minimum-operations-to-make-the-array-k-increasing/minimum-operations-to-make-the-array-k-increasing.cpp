class Solution
{
    public:
        int kIncreasing(vector<int> &arr, int k)
        {
            vector<vector < int>> vec(k, vector<int> ());
            int n = arr.size();
            for (int i = 0; i < k; i++)
            {
                for (int j = i; j < n; j += k)
                {
                    vec[i].push_back(arr[j]);
                }
            }
            int ans = 0;
            for (int i = 0; i < k; i++)
            {
                auto nums = vec[i];
                vector<int> dp;
                for (auto it: nums)
                {
                    if(dp.size()==0){
                        dp.push_back(nums[0]);
                        continue;
                    }
                    if (it >= dp.back())
                    {
                        dp.push_back(it);
                    }
                    else
                    {
                        int index = upper_bound(dp.begin(), dp.end(), it) - dp.begin();
                        dp[index] = it;
                    }
                }
                ans += (nums.size() - dp.size());
            }
            return ans;
        }
};