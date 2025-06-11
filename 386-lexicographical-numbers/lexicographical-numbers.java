class Solution {
    List<Integer> ans;

    private void solve(int curr, int end) {
        if (curr > end) return;
        if (curr != 0) {
            ans.add(curr);
        }
        for (int i = 0; i <= 9; i++) {
            if (i == 0 && curr == 0) continue;
            solve(curr * 10 + i, end);
        }
        return;
    }

    public List<Integer> lexicalOrder(int n) {
        ans = new ArrayList<>();
        solve(0, n);
        return ans;
    }
}
