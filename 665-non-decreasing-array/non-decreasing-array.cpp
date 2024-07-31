class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        vector<int>dp;
        for(auto it:nums)
        {
            if(dp.size()==0 || dp.back()<=it){
                dp.push_back(it);
            }else{
                int index=upper_bound(dp.begin(),dp.end(),it)-dp.begin();
                dp[index]=it;
            }
        }
        return nums.size()<=dp.size()+1;
    }
};