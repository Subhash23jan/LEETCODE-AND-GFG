class Solution
{
    public:
        int appendCharacters(string s, string t)
        {
            int index = 0;
            for (auto it: s)
            {
                if (index < t.size() && it == t[index])
                {
                    index++;
                }
            }
            return t.size() - index;
        }
};