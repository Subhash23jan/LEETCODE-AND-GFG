class Solution
{
    public:
        bool isMonotonic(vector<int> &nums)
        {
            int i = 0;
            int diff = 0;
            while (diff == 0 && i < nums.size() - 1)
            {
                diff = nums[i+1] - nums[i];
                i++;
            }
            while (i < nums.size() - 1)
            {
                if(diff>0)
                {
                    if(nums[i]>nums[i+1])
                     return false;
                }else{
                    if(nums[i]<nums[i+1])
                     return false;
                }
                i++;
            }
            return true;
        }
};