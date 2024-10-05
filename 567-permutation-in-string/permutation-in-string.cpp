class Solution
{
    bool areEqual(vector<int> a, vector<int> b)
    {
        for (int i = 0; i < 26; i++)
        {
            if (a[i] != b[i])
                return false;
        }
        return true;
    }
    public:
        bool checkInclusion(string s1, string s2)
        {
            vector<int> freq1(26, 0);
            vector<int> freq2(26, 0);
            for (auto ch: s1)
                freq1[ch - 'a']++;
            int i = 0, j = 0;
            while (j < s2.size())
            {
                freq2[s2[j] - 'a']++;
                if (j - i + 1 == s1.size())
                {
                    if (areEqual(freq1, freq2))
                        return true;
                }
                if (j - i + 1 < s1.size())
                    j++;
                else
                {
                    freq2[s2[i] - 'a']--;
                    j++;
                    i++;
                }
            }
            return false;
        }
};