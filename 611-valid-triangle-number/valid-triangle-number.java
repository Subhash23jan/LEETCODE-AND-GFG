class Solution {

    int solve(int sum, int l, int r, int[] nums) {
        int ans = r + 1;
        while (l <= r) {
            int mid = (r + l) / 2;
            if (nums[mid] >= sum) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    public int triangleNumber(int[] nums) {
        int ans = 0, n = nums.length;
        Arrays.sort(nums);

        int prev = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int ind = solve(nums[i] + nums[j], j + 1, n - 1, nums);
                ans += (ind - (j + 1));
            }
        }
        return ans;
    }
}
