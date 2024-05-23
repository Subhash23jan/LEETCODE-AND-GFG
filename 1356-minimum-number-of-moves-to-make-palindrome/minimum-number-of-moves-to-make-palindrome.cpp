class Solution
{
    public:
        int minMovesToMakePalindrome(string s)
        {
            int ans = 0;
            int l = 0, r = s.size() - 1;
            while (l < r)
            {
                if (s[l] == s[r])
                {
                    l++;
                    r--;
                }
                else
                {
                    int i = r - 1;
                    while (s[i] != s[l]) i--;
                    if (i == l)
                    {
                        swap(s[i], s[i+ 1]);
                        ans++;
                    }
                    else
                    {
                        while (i < r)
                        {
                            swap(s[i], s[i + 1]);
                            ans++;
                            i++;
                        }
                        l++;
                        r--;
                    }
                }
            }
            return ans;
        }
};