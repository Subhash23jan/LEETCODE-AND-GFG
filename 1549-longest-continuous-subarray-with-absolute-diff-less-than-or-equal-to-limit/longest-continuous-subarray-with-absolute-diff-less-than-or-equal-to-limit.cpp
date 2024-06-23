class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans = 0, i = 0, j = 0, n = nums.size();
        std::multiset<int> st1, st2;
        while (j < n) {
            st1.insert(nums[j]);
            st2.insert(-nums[j]);
            while (*st1.rbegin() - *st1.begin() > limit) {
                st1.erase(st1.find(nums[i]));
                st2.erase(st2.find(-nums[i]));
                i++;
            }
            ans = std::max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};