class Solution
{
    public:
        vector<int> maximumBeauty(vector<vector < int>> &items, vector< int > &queries)
        {
            map<int, int> mp;

            sort(items.begin(), items.end());

            mp[items[0][0]] = items[0][1];
            for (int i = 1; i < items.size(); i++)
            {
                mp[items[i][0]] = max(items[i][1], mp[items[i - 1][0]]);
            }

            vector<int> ans;
            for (auto query: queries)
            {
                auto it = mp.upper_bound(query);
                if (it == mp.begin())
                {
                    ans.push_back(0);
                }
                else
                {
                    --it;
                    ans.push_back(it->second);
                }
            }

            return ans;
        }
};