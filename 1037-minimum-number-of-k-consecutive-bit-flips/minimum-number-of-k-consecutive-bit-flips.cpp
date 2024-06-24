class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        vector<bool>arr(n,false);
        int incr=0;
        for(int i=0;i<n;i++)
        {
            if(i>=k){
                if(arr[i-k]){
                    incr--;
                }
            }
            if(nums[i]==incr%2){
                if(i+k>n) return -1;
                arr[i]=true;
                incr++;
                ans++;
            }
        }
        return ans;
    }
};