class Solution {
    int mod = 1e9 + 7, base = 31;
    vector<long long> hash, pow;

    long long getHash(int l, int r) {
        long long res = (hash[r + 1] - (hash[l] * pow[r - l + 1]) % mod + mod) % mod;
        return res;
    }

    bool isSame(vector<int>& nums, int l1, int r1, int l2, int r2) {
        int len1 = r1 - l1 ;
        int len2 = r2 - l2;
        if (len1 != len2) return false;
        return getHash(l1, r1) == getHash(l2, r2);
    }

public:
    int beautifulSplits(vector<int>& nums) {
        int n = nums.size(), count = 0;
        hash.resize(n + 1, 0);
        pow.resize(n + 1, 1);

        for (int i = 0; i < n; i++) {
            hash[i + 1] = (hash[i] * base + nums[i]) % mod;
            pow[i + 1] = (pow[i] * base) % mod;
        }

        for (int i = 1; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int len1 = i;
                int len2 = j - i;
                int len3 = n - j;
                bool ans1 = false, ans2 = false;

                if (len1 <= len2 && isSame(nums, 0, i - 1, i, i + len1 - 1)) {
                    ans1 = true;
                }
                if (len2 <= len3 && isSame(nums, i, j - 1, j, j + len2 - 1)) {
                    ans2 = true;
                }

                if (ans1 || ans2) count++;
            }
        }

        return count;
    }
};
