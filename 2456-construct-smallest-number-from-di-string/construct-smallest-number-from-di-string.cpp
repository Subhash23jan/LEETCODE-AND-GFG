class Solution
{
    string solve(int i, int prev, int vis, string &pattern, string num)
    {
        if (i == pattern.size()) return num;
        string ans = "~";

        for (int k = 1; k <= 9; k++)
        {
            if (!(vis &(1 << k)))
            {
                if ((pattern[i] == 'D' && prev > k) || (pattern[i] == 'I' && prev < k))
                {
                    ans = min(ans, solve(i + 1, k, vis | (1 << k), pattern, num + char(k + '0')));
                }
            }
        }
        return ans;
    }

    public:
        string smallestNumber(string pattern)
        {
            string ans = "~";

            for (int i = 1; i <= 9; i++)
            {
                ans = min(ans, solve(0, i, (1 << i), pattern, string(1, i + '0')));
            }
            return ans;
        }
};