class Solution
{
    public:
        long long minimumSteps(string s)
        {
            long long ans = 0;
            int i = 0, j = 0;
            int n = s.size();
            while (i < n && j < n)
            {
                if (s[j] == '0')
                {
                    swap(s[i], s[j]);
                    ans += (j - i);
                    i++;
                }
                j++;
            }
            return ans;
        }
};