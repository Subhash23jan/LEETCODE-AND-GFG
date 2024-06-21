class Solution {
    int dp[5001][2];
    int solve(int i,vector<int>& nums,bool isBought)
    {
        if(i>=nums.size()) return 0;
        if(dp[i][isBought]!=-1)
        {
            return dp[i][isBought];
        }
        int ans=solve(i+1,nums,isBought);
        if(isBought)
        {
           ans=max(ans,nums[i]+solve(i+2,nums,false));
        }else{
            ans=max(ans,-nums[i]+solve(i+1,nums,true));
        }
        return dp[i][isBought]=ans;
    }
public:
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return solve(0,prices,false);
    }
};