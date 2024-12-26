#define ll long long
class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<ll> pre(n, 0);
        pre[0] = 1ll * nums[0];
        for (int i = 1; i < n; i++)
            pre[i] = pre[i - 1] + 1ll * nums[i];

        vector<ll> ans;
        for (int q : queries) {
            auto it = --upper_bound(nums.begin(), nums.end(), q);
            int i = it - nums.begin();

            long long x = (i < 0) ? 0 : (1ll * (i + 1) * q - pre[i]);
            long long y = (i < 0)
                              ? (pre[n - 1] - 1ll * n * q)
                              : (pre[n - 1] - pre[i] - 1ll * (n - i - 1) * q);

            ans.push_back(x + y);
        }
        return ans;
    }
};