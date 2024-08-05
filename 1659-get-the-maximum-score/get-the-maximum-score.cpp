class Solution
{
    public:
        int maxSum(vector<int> &nums1, vector<int> &nums2)
        {
            long long sum1 = 0, sum2 = 0, ans = 0, i = 0, j = 0;
            int mod=1e9+7;
            while (i < nums1.size() && j < nums2.size())
            {
                if (nums1[i] == nums2[j])
                {
                    ans = (ans+max(sum1, sum2))%mod;
                    sum1 = 0;
                    sum2 = 0;
                    ans += nums1[i];
                    i++;
                    j++;
                }
                else if (nums1[i] > nums2[j])
                {
                    sum2 += nums2[j];
                    j++;
                }
                else
                {
                    sum1 += nums1[i];
                    i++;
                }
            }
            while (i < nums1.size()) sum1 += nums1[i++];
            while (j < nums2.size()) sum2 += nums2[j++];
            ans = (ans+max(sum1, sum2))%mod;
            return ans;
        }
};