class Solution
{
    public:
        int numOfSubarrays(vector<int> &arr, int k, int threshold)
        {
            int sum = 0, l = 0, r = 0;
            int n = arr.size();
            int ans = 0;
            while (r < n)
            {
                sum += arr[r++];
                while (r - l > k)
                {
                    sum -= arr[l];
                    l++;
                }
                if (r - l == k && sum / k >= threshold) ans++;
            }
            return ans;
        }
};