class Solution
{
    public:
        bool check(vector<int> &nums)
        {
            vector<int> arr = nums;
            int n = nums.size();
            for (auto it: nums)
            {
                arr.push_back(it);
            }
            int i = 1;
            for (int k = 1; k < arr.size(); k++)
            {
                if (arr[k] >= arr[k - 1])
                {
                    i++;
                }
                else
                {
                    i = 1;
                }
                if (i >= n) return true;
            }
            return (i == n);
        }
};