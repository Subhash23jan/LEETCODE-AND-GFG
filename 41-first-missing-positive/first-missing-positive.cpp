class Solution
{
    public:
        int firstMissingPositive(vector<int> &nums)
        {
            int n = nums.size(), i = 0;
            while (i < n)
            {
                int val = nums[i];
                if (val >= n || val < 0 || val == i || nums[val] == nums[i])
                {
                    i++;
                    continue;
                }
                else
                {
                    swap(nums[i], nums[val]);
                }
            }
            int num = 1;
            for (int i = 1; i < n; i++)
            {
                if (num != nums[i]) return num;
                num++;
            }
            return nums[0] == num ? num + 1 : num;
        }
};