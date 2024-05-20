class Solution {
    int solve(int i,vector<int>nums,int xr)
    {
        if(i==nums.size()) return xr;
        int ans=0;
        ans+=solve(i+1,nums,xr);
        xr^=nums[i];
        ans+=solve(i+1,nums,xr);
        return ans;
    }
public:
    int subsetXORSum(vector<int>& nums) {
        return solve(0,nums,0);
    }
};