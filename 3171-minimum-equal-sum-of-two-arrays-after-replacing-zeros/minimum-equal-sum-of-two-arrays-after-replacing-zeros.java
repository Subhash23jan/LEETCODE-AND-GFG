class Solution {

    public long minSum(int[] nums1, int[] nums2) {
        long sum1 = 0, sum2 = 0;
        int cnt1 = 0, cnt2 = 0;
        for (int val : nums1) {
            sum1 += val;
            cnt1 += (val == 0) ? 1 : 0;
        }
        for (int val : nums2) {
            sum2 += val;
            cnt2 += (val == 0) ? 1 : 0;
        }
        long minSum1 = sum1 + cnt1, minSum2 = sum2 + cnt2;
        if (minSum1 == minSum2) return minSum1;
        if (sum1 > sum2) {
            if ((cnt1 == 0 && minSum2 > minSum1) || (cnt2 == 0 && cnt1 != 0)) return -1;
        } else if (sum1 < sum2) {
            if ((cnt2 == 0 && minSum2 < minSum1) || (cnt1 == 0 && cnt2 != 0)) return -1;
        } else {
            if (cnt1 == 0 || cnt2 == 0) return -1;
        }
        if (sum1 != sum2 && cnt1 == 0 && cnt2 == 0) return -1;
        return Math.max(minSum1, minSum2);
    }
}
