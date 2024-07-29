class Solution
{
    int solve(int index, vector<int> &nums, bool isIncrease)
    {
        int ans = 0;
        if (isIncrease)
        {
            for (int i = index; i < nums.size(); i++)
            {
                if (nums[i] < nums[index - 1])
                {
                    continue;
                }
                for (int j = i + 1; j < nums.size(); j++)
                {
                    if (nums[i] < nums[j]) ans++;
                }
            }
        }
        else
        {
            for (int i = index; i < nums.size(); i++)
            {
                if (nums[index - 1]<nums[i])
                {
                    continue;
                }
                for (int j = i + 1; j < nums.size(); j++)
                {
                    if (nums[i] > nums[j]) ans++;
                }
            }
        }
        return ans;
    }
    public:
        int numTeams(vector<int> &rating)
        {
            int ans = 0;
            for (int i = 0; i < rating.size() - 2; i++)
            {
                ans += solve(i + 1, rating, false);
                ans += solve(i + 1, rating, true);
            }
            return ans;
        }
};