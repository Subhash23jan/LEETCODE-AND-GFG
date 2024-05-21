class Solution {
    void solve(int i,vector<int>nums,vector<int>temp,vector<vector<int>>&ans)
    {
        if(i==nums.size()){
            ans.push_back(temp);
            return ;
        }
        solve(i+1,nums,temp,ans);
        temp.push_back(nums[i]);
        solve(i+1,nums,temp,ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>ans;
      //  ans.push_back(temp);
         solve(0,nums,temp,ans);
         return ans;
    }
};