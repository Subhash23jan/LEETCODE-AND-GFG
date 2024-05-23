class Solution
{
    public:
        void bs(vector<int> &nums, unordered_map<int, int> &mymap, int &finalans,
            int index, int k)
        {
            if (index >= nums.size())
            {
                finalans++;
                return;
            }

           	// include only after checking
            if (mymap[nums[index] - k] == 0)
            {

                mymap[nums[index]]++;
                bs(nums, mymap, finalans, index + 1, k);
                mymap[nums[index]]--;

               	// dont include
            }
            bs(nums, mymap, finalans, index + 1, k);
        }
    int beautifulSubsets(vector<int> &nums, int k)
    {

        sort(nums.begin(), nums.end());
        unordered_map<int, int> mymap;
        int finalans = 0;

        bs(nums, mymap, finalans, 0, k);
        return finalans - 1;
    }
};