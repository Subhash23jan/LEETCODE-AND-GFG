class Solution
{
    public:
        bool backspaceCompare(string s, string t)
        {
            int i = s.size() - 1, j = t.size() - 1, cnts = 0, cntt = 0;
            while (i >= 0 || j >= 0)
            {
                char s_ch = '#';
                while (i >= 0)
                {
                    if (s[i] == '#')
                    {
                        cnts++;
                        i--;
                        continue;
                    }
                    if (cnts == 0 )
                    {
                        s_ch = s[i];
                        i--;
                        break;
                    }
                    cnts--;
                    i--;
                }
                char t_ch = '#';
                while (j >= 0)
                {
                    if (t[j] == '#')
                    {
                        cntt++;
                        j--;
                        continue;
                    }
                    if (cntt == 0 )
                    {
                        t_ch = t[j];
                        j--;
                        break;
                    }
                    cntt--;
                    j--;
                }
                if (s_ch != t_ch) return false;
            }
            return true;
        }
};