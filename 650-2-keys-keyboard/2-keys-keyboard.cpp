class Solution {
private:
    int targetLength;
    vector<vector<int>> cache;

    int calculateMinOps(int i, int j) {
        if (i == targetLength) return 0;
        if (i > targetLength) return INT_MAX / 2;

        if (cache[i][j] != -1) {
            return cache[i][j];
        }

        int pasteOption = 1 + calculateMinOps(i + j, j);
        int copyPasteOption = 2 + calculateMinOps(i * 2, i);

        int result = min(pasteOption, copyPasteOption);
        cache[i][j] = result;

        return result;
    }

public:
    int minSteps(int n) {
        if (n == 1) return 0;
        targetLength = n;
        cache = vector<vector<int>>(n + 1, vector<int>(n / 2 + 1, -1));
        return 1 + calculateMinOps(1, 1);
    }
};