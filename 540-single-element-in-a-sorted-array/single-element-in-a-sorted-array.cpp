class Solution
{
    int solve(int l, int r, vector<int> &nums, int n)
    {
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (mid + 1 < n && nums[mid + 1] == nums[mid])
            {

                if ((mid + 1) % 2 != 0)
                {
                    l = mid + 2;
                }
                else
                {
                    r = mid - 1;
                }
            }
            else if (mid > 0 && nums[mid - 1] == nums[mid])
            {
                if ((mid - 1) % 2 == 0)
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
            else
            {
                return nums[mid];
            }
        }
        return 0;
    }
    public:
        int singleNonDuplicate(vector<int> &nums)
        {
            return solve(0, nums.size() - 1, nums, nums.size());
        }
};