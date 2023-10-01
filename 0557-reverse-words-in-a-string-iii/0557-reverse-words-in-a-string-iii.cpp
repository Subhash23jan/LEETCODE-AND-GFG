class Solution
{
    public:
        string reverseWords(string s)
        {
            int i = 0;
            string ans;
            while (i < s.size())
            {
                string str = "";
                while (i < s.size() && s[i] != ' ')
                {
                    str += s[i];
                    i++;
                }
                i++;
                if (ans.size())
                    ans += " ";
                reverse(str.begin(), str.end());
                ans += str;
            }
            return ans;
        }
};