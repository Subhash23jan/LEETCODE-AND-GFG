class Solution
{
    public:
        int findDuplicate(vector<int> &nums)
        {
            map<int, int> mp;
            vector<int>arr(nums.size(),0);
            for (int i = 0; i < nums.size(); i++)
            {
               	// if(mp.find(nums[i])!=mp.end())
               	//         return nums[i];
               	// else
               	//         mp[nums[i]]++;
                arr[nums[i]]++;
                if (arr[nums[i]] == 2)
                    return nums[i];
            }
            return 0;
        }
};