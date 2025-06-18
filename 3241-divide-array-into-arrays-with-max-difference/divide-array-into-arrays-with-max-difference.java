class Solution {

    public int[][] divideArray(int[] nums, int k) {
        Arrays.sort(nums);
        int r = nums.length / 3, ind = 0;
        int ans[][] = new int[r][3];
        for (int i = 0; i < r; i++) {
            int temp[] = new int[3];
            for (int j = 0; j < 3; j++) {
                temp[j] = nums[ind++];
            }
            if (Math.abs(temp[0] - temp[2]) > k) return new int[0][];
            ans[i] = temp;
        }
        return ans;
    }
}
