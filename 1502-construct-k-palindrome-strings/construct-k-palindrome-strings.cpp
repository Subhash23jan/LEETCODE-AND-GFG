class Solution
{
    public:
        bool canConstruct(string s, int k)
        {
            int n = s.size();
            if (n < k) return false;
            unordered_map<char, int> mp;
            for (auto it: s)
            {
                mp[it]++;
            }
            int cnt = 0;
            for (auto it: mp)
            {
                if (it.second % 2) cnt++;
            }
            return cnt <= k;
        }
};