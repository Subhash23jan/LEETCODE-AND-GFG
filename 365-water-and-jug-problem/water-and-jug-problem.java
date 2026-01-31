class Solution {
    private static final int[][] vis = new int[1001][1001];

    public static boolean solve(int x, int y, int waterInX, int waterInY, int target) {
        if (waterInX + waterInY == target) return true;
        if (vis[waterInX][waterInY] == 1) return false;
        vis[waterInX][waterInY] = 1;
        if (solve(x, y, x, waterInY, target)) return true;
        if (solve(x, y, waterInX, y, target)) return true;
        if (solve(x, y, 0, waterInY, target)) return true;
        if (solve(x, y, waterInX, 0, target)) return true;

        int needX = x - waterInX;
        int needY = y - waterInY;

        if (needX > 0 && waterInY > 0) {
            int poured = Math.min(needX, waterInY);
            if (solve(x, y, waterInX + poured, waterInY - poured, target)) return true;
        }

        if (needY > 0 && waterInX > 0) {
            int poured = Math.min(needY, waterInX);
            if (solve(x, y, waterInX - poured, waterInY + poured, target)) return true;
        }

        return false;
    }

    public boolean canMeasureWater(int x, int y, int target) {
        for (int i = 0; i < 1001; i++) Arrays.fill(vis[i], -1);
        return solve(x, y, 0, 0, target);
    }
}
