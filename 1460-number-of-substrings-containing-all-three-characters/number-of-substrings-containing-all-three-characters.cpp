class Solution
{
    public:
        int numberOfSubstrings(string s)
        {
            int a = -1, b = -1, c = -1;
            int j = 0, i = 0, n = s.size(), ans = 0;
            map<char, int> mp;
            while (j < n)
            {
                mp[s[j]]++;
                while (mp.size() == 3)
                {
                    ans += (n - j);
                    mp[s[i]]--;
                    if (mp[s[i]] == 0)
                    {
                        mp.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
            return ans;
        }
};