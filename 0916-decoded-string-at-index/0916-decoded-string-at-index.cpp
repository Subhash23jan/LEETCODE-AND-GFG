class Solution
{
public:
    string decodeAtIndex(string s, int k)
    {
        long long size = 0; // Use long long to handle large sizes
        for (int i = 0; i < s.size(); i++)
        {
            if (isdigit(s[i]))
            {
                int digit = s[i] - '0';
                size *= digit;
            }
            else
            {
                size++;
            }
        }
        
        for (int i = s.size() - 1; i >= 0; i--)
        {
            char c = s[i];
            if (isdigit(c))
            {
                int digit = c - '0';
                size /= digit;
                k %= size;
            }
            else
            {
                if (k == 0 || k == size)
                {
                    return string(1, c);
                }
                size--;
            }
        }
        
        return "";
    }
};
