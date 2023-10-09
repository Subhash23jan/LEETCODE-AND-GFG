class Solution
{
    int leftMost(vector<int> &nums, int target, int low, int high)
    {
        int ans = -1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
            {
                ans = mid;
                high = mid - 1;
            }
            else if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }
    int rightMost(vector<int> &nums, int target, int low, int high)
    {
        int ans = -1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
            {
                ans = mid;
                low = mid + 1;
            }
            else if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }
    public:
        vector<int> searchRange(vector<int> &nums, int target)
        {
            int low = 0, high = nums.size() - 1;
            vector<int> ans(2, -1);
            while (low <= high)
            {
                int mid = (low + high) / 2;
                if (nums[mid] == target)
                {
                    ans[0] = leftMost(nums, target, low, mid);
                    ans[1] = rightMost(nums, target, mid, high);
                    return ans;
                }
                else if (nums[mid] < target)
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
            return ans;
        }
};