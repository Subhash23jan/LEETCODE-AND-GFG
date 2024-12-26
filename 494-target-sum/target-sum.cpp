class Solution {
public:
    int solve(vector<int>& nums,int i,int target,int sum)
    {
            if(i==0 && sum==target)
                    return 1;
            if(i==0)
                    return 0;
            return solve(nums,i-1,target,sum+nums[i-1])+solve(nums,i-1,target,sum-nums[i-1]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
            int n=nums.size();
        return solve(nums,n,target,0);
    }
};