class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1); 
    }
    
    int atMost(vector<int>& nums, int k) {
        int s = 0, ans = 0;
        for(int i = 0, j = 0; i < nums.size(); i++) {
            s += nums[i] % 2;
            while(s > k) s -= (nums[j++] % 2);
            ans += (i - j + 1);
        }
        return ans;
    }
};