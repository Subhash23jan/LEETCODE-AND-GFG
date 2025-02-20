class Solution {
    string solve(string str, int n, int &k) {
        if (n == 0) {
            k--;
            if (k == 0) return str;
            return "";
        }
        char prev = str.empty() ? '#' : str.back();
        for (char ch = 'a'; ch <= 'c'; ch++) {
            if (ch != prev) {
                string ans = solve(str + ch, n - 1, k);
                if (!ans.empty()) return ans;
            }
        }
        return "";
    }

public:
    string getHappyString(int n, int k) {
        return solve("", n, k);
    }
};
