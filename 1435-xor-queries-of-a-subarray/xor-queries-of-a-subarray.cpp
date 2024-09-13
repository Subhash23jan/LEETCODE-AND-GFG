class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector<int>dp(n,0);
        vector<int>ans;
        dp[0]=arr[0];
        for(int i=1;i<n;i++)
        {
            dp[i]=dp[i-1]^arr[i];
        }
        for(auto it:queries){
            int xr=dp[it[1]];
            if(it[0]>0)xr^=dp[it[0]-1];
            ans.push_back(xr);
        }
        return ans;
    }
};