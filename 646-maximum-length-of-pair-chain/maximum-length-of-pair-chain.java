class Solution {

    public int findLongestChain(int[][] pairs) {
        Arrays.sort(pairs, (a, b) -> a[1] - b[1]); 
        int currEnd = Integer.MIN_VALUE, ans = 0;
        for (int[] p : pairs) {
            if (p[0] > currEnd) { 
                currEnd = p[1];
                ans++;
            }
        }
        return ans;
    }
}
