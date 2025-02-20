class Solution
{
    string solve(string str, int n, set<string> &st)
    {
        if (n == 0)
        {
            if (st.count(str)) return "";
            return str;
        }
        auto ans1 = solve(str + "0", n - 1, st);
        if (ans1 != "") return ans1;
        return solve(str + "1", n - 1, st);
    }
    public:
        string findDifferentBinaryString(vector<string> &nums)
        {
            set<string> st(nums.begin(), nums.end());
            return solve("", nums.size(), st);
        }
};