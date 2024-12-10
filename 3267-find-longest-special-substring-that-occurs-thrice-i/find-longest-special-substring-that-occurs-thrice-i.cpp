class Solution
{
    public:
        int maximumLength(string s)
        {
            map<char, vector < int>> hash;
            map<char, int> mp;
            int i = 0, j = 0;
            int ans = -1;
            while (i < s.size())
            {
                mp[s[i++]]++;
                while (j < i && mp.size() > 1)
                {
                    mp[s[j]]--;
                    if (mp[s[j]] == 0)
                    {
                        mp.erase(s[j]);
                    }
                    j++;
                }
                string str = s.substr(j, i - j);
                int temp = str.size();
                hash[s[i - 1]].push_back(temp);
            }
            for (auto it: hash)
            {
                auto vec = it.second;
                if (vec.size() > 2)
                {
                    sort(vec.rbegin(), vec.rend());
                    ans = max(ans, vec[2]);
                }
            }
            return ans;
        }
};