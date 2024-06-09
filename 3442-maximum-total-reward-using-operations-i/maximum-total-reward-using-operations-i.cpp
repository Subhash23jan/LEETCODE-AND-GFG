class Solution {
public:
    vector<vector<int>> dp; // Memoization table
    
    int solve(int i, int sum, vector<int>& nums) {
        if (i == nums.size()) return sum; // Base case: reached end of array
        
        if (dp[i][sum] != -1) return dp[i][sum]; // Return memoized result
        

        int ans = solve(i + 1, sum, nums);
   
        if (nums[i] > sum) {
            ans = max(ans, solve(i + 1, sum + nums[i], nums));
        }
        return dp[i][sum] = ans;
    }
    
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(), rewardValues.end());
        
      
        int n = rewardValues.size();
        dp.assign(n+1, vector<int>(4004 + 1, -1));
        
     
        return solve(0, 0, rewardValues);
    }
};