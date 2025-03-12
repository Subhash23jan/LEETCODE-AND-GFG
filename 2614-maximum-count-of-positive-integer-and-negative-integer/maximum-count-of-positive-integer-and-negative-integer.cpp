class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=n-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(nums[mid]>=0){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        int neg=l;
        l=0,r=n-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(nums[mid]<=0){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return max(neg,n-l);

    }
};