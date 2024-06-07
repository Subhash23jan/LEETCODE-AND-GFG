class Solution {
    int helpme(int ind, int walls, vector<int> &cost, vector<int> &time, vector<vector<int>>&dp)
    {
        int n = cost.size();
        if(walls <= 0) return 0;
        if(ind == n) return 1e9;
        if (dp[ind][walls] != -1)   return dp[ind][walls];
        
        
        int notTake = helpme(ind + 1, walls, cost, time, dp);
        int take = cost[ind] + helpme(ind + 1, walls - (time[ind] + 1), cost, time, dp);
        
        return dp[ind][walls] = min(notTake, take);
    }
public:
    int paintWalls(vector<int>& cost, vector<int>& time)
    {
        int n = cost.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return helpme(0,cost.size(), cost, time, dp);
    }
};