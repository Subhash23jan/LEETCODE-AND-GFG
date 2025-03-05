class Solution
{
    public:
        vector<int> findClosestElements(vector<int> &arr, int k, int x)
        {
            vector<int> ans;
            auto ind = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
            int l = ind - 1, r = ind;

            while (k--)
            {
                if (l < 0)
                {
                    r++;
                    continue;
                }
                if (r >= arr.size())
                {
                    l--;
                    continue;
                }
                if (abs(arr[l] - x) <= abs(arr[r] - x))
                {
                    l--;
                }
                else
                {
                    r++;
                }
            }

            for (int i = l + 1; i < r; i++)
            {
                ans.push_back(arr[i]);
            }
            return ans;
        }
};