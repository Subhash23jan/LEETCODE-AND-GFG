class Solution {
    bool solve(long long mid, vector<int>& ranks, int cars) {
        long long cnt = 0;
        for (auto it : ranks) {
            cnt += (long long)(sqrt(mid / it));
            if (cnt >= cars) return true;
        }
        return cnt >= cars;
    }
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long ans = 0, l = 0, r = 1e14;
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            if (solve(mid, ranks, cars)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
