class Solution {
public:

    int f(int i,int diff,vector<int> &nums,vector<unordered_map<int,int>> &mpp){
        if(mpp[i].count(diff) )return mpp[i][diff];
        for(int j = i+1;j < nums.size();j++){
            if(nums[j] - nums[i] == diff)
            return mpp[i][diff] = 1 + f(j,diff,nums,mpp);
        }
        return mpp[i][diff] = 0;
    }

    int longestArithSeqLength(vector<int>& nums) {
        // int n = nums.size();
        // int ans = 0;
        // vector<unordered_map<int,int>>mpp(n);
        // vector<vector<int>> dp(n,vector<int>(501,-1));
        // for(int i = 0;i < n;i++){
        //     for(int j = i + 1;j < n;j++){
        //         int diff = nums[j] - nums[i];
        //         ans = max(ans,2 + f(j,diff,nums,mpp));
        //     }
        // }
        // return ans;

        int n = nums.size();
        int ans = 0;
        unordered_map<int,int>mpp[n];
        for(int i = 0;i < n;i++){
            for(int j = 0;j < i;j++){
                int diff = nums[i] - nums[j];
                int ct = 1;
                if(mpp[j].count(diff))ct = mpp[j][diff];
                mpp[i][diff] = 1 + ct;
                ans = max(ans,mpp[i][diff]);
            }
        }
        return ans;
    }
};