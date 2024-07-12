class Solution {
    stack<char> st;

    int collectPoints(string s, string str, int p) {
        int ans = 0;
        for (auto it : s) {
            if (!st.empty() && st.top() == str[0] && str[1] == it) {
                ans += p;
                st.pop();
            } else {
                st.push(it);
            }
        }
        return ans;
    }

public:
    int maximumGain(string s, int x, int y) {
        int ans = 0;
        string str = "";

        if (x > y) {
            ans += collectPoints(s, "ab", x);

            while (!st.empty()) {
                str += st.top();
                st.pop();
            }
            reverse(str.begin(), str.end());

            ans += collectPoints(str, "ba", y);
        } else {
            ans += collectPoints(s, "ba", y);

            while (!st.empty()) {
                str += st.top();
                st.pop();
            }
            reverse(str.begin(), str.end());

            ans += collectPoints(str, "ab", x);
        }

        return ans;
    }
};
