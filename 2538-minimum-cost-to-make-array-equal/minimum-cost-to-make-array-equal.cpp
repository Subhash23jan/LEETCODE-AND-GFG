class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long l=1,r=1e6;
        long long  ans=LONG_LONG_MAX;
        while(l<r)
        {
            long long mid=(l+r)/2;
            long long sum1=0,sum2=0;
            for(int i=0;i<nums.size();i++)
            {
                sum1+=(abs(nums[i]-mid)*cost[i]);
                sum2+=(abs(nums[i]-mid-1)*cost[i]);
            }
            ans=min(sum1,sum2);
            if(sum1<sum2)
            {
                r=mid;
            }else{
                l=mid+1;
            } 
        }
        return ans;
    }
};