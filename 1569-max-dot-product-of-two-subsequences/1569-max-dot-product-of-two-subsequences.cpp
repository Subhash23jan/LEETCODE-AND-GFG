class Solution {
    map<pair<int,pair<int,bool>>,int>dp;
    int solve(int i,int j,vector<int>& nums1, vector<int>& nums2,bool flag)
    {
        if(i==nums1.size() || j==nums2.size())
        {
            return flag?0:-1001; 
             
        }
        if(dp.find({i,{j,flag}})!=dp.end())
         return dp[{i,{j,flag}}];
        int take=(nums1[i]*nums2[j])+solve(i+1,j+1,nums1,nums2,true);
        int skipFirst=solve(i+1,j,nums1,nums2,flag);
        int skipSecond=solve(i,j+1,nums1,nums2,flag);
        return dp[{i,{j,flag}}]=max({take,skipFirst,skipSecond});
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
   
    return solve(0,0,nums1,nums2,false);
    }
};