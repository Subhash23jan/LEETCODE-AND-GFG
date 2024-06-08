class Solution {
    int dp[501][501];
    int solve(int l,int r,vector<int>& stoneValue,int sum)
    {
        if(l==r){
            return 0;
        }
        if(dp[l][r]!=-1)return dp[l][r];
        int leftSum=0;
        int ans=0;
        for(int i=l;i<r;i++){
            leftSum+=stoneValue[i];
            int rightSum=sum-leftSum;
            if(leftSum<rightSum){
                ans=max(ans,leftSum+solve(l,i,stoneValue,leftSum));
            }else if(leftSum>rightSum){
                ans=max(ans,rightSum+solve(i+1,r,stoneValue,rightSum));
            }else{
                int temp=max(leftSum+solve(l,i,stoneValue,leftSum),rightSum+solve(i+1,r,stoneValue,rightSum));
                ans=max(ans,temp);
            }
        }
        return dp[l][r]=ans;
    }
public:
    int stoneGameV(vector<int>& stoneValue) {
        int sum=0;
        for(auto it:stoneValue){
            sum+=it;
        }
        int n=stoneValue.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,n-1,stoneValue, sum);
    }
};