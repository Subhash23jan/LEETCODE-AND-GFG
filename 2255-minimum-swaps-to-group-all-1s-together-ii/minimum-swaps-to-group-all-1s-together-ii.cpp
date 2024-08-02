class Solution {
    int solve(int val,int cnt,vector<int>nums)
    {
        int temp=0,r=0,l=0;
        int ans=nums.size();
        while(r<nums.size()){
            if(nums[r]!=val){
               temp++;
            }
            if(r-l+1>cnt)
            {
                if(nums[l]!=val){
                    temp--;
                }
                l++;
            }
            if(r-l+1==cnt){
                ans=min(ans,temp);
            }
            r++;
        }
        return ans;
    }
public:
    int minSwaps(vector<int>& nums) {
        int cnt=0,ones=0;
        for(auto it:nums)
        {
            if(it==0){
                cnt++;
            }
        }
        return min(solve(1,nums.size()-cnt,nums),solve(0,cnt,nums));
    }
};