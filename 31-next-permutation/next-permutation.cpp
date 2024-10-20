class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int idx = -1;
        int n = nums.size();
        int i = n - 2;
        
        while (i >= 0)
        {
            if (nums[i] < nums[i + 1])
            {
                idx = i; 
                break;
            }
            i--;
        }
        
        if (idx == -1)
        {
            reverse(nums.begin(), nums.end());  // corrected parentheses
            return;
        }

        reverse(nums.begin() + idx + 1, nums.end());  // corrected parentheses
        
        for (int i = idx + 1; i < n; i++)
        {
            if (nums[i] > nums[idx])
            {
                swap(nums[i], nums[idx]);
                return;
            }
        }
    }
};
