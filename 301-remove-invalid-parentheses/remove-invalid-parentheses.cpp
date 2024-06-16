class Solution
{
    int size = 0;
    void solve(int i, string str, string s, int cnt, int skippable, vector<string> &ans)
    {
        if (i >= s.size())
        {
            if(skippable==0 && cnt==0){
                ans.push_back(str);
            }
            return;
        }
        if (skippable < 0) return;
        if (cnt >= size) return;
        char ch = s[i];
        if (ch == '(')
        {
            solve(i + 1, str + '(', s, cnt + 1, skippable, ans);
            solve(i + 1, str, s, cnt, skippable - 1, ans);
        }
        else if (ch == ')')
        {
            if (cnt > 0)
            {
                solve(i + 1, str + ')', s, cnt - 1, skippable, ans);
            }
            solve(i + 1, str, s, cnt, skippable - 1, ans);
        }
        else
        {
            solve(i + 1, str + s[i], s, cnt, skippable, ans);
        }
    }
    public:
        vector<string> removeInvalidParentheses(string s)
        {
            stack<int> st;
            int n = s.size(), cnt = 0;
            vector<string> ans;
            vector<int> arr(n, 0);
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '(')
                {
                    st.push(i);
                }
                else if (s[i] == ')')
                {
                    if (st.size())
                    {
                        arr[i] = 1;
                        arr[st.top()] = 1;
                        st.pop();
                    }
                }
                else
                {
                    arr[i] = 1;
                }
            }
            for (auto it: arr)
            {
                cnt += it;
            }
            cout << cnt << endl;
            size = cnt;
            if (cnt == 0)
            {
                ans.push_back("");
                return ans;
            }
            solve(0, "", s, 0, n - cnt, ans);

            unordered_set<std::string > temp(ans.begin(), ans.end());
            ans.assign(temp.begin(), temp.end());

            return ans;
        }
};