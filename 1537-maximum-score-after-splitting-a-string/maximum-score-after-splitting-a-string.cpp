class Solution
{
    public:
        int maxScore(string s)
        {
            int one = 0, zero = 0;
            for (auto it: s)
            {
                one += (it == '1');
            }
            int ans = 0;
            for (int i = 0; i < s.size() - 1; i++)
            {
                if (s[i] == '0')
                {
                    zero++;
                }
                else
                {
                    one--;
                }
                ans = max(ans, zero + one);
            }
            return ans;
        }
};