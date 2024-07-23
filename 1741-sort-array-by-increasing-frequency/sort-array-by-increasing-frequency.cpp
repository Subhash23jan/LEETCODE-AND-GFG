class Solution
{
    public:
        vector<int> frequencySort(vector<int> &nums)
        {
            map<int, int> mp;
            for (auto it: nums)
            {
                mp[it]++;
            }
            vector<pair<int, int>> vp;
            for (auto it: mp)
            {
                int k = it.second;
                while (k--)
                {
                    vp.push_back({ it.second,
                        it.first });
                }
            }
            sort(vp.begin(), vp.end(), [](pair<int, int> p1, pair<int, int> p2)
            {
                if (p1.first == p2.first)
                {
                    return p1.second > p2.second;
                }
                return p1.first < p2.first;
	});
            vector<int> ans;
            for (auto it: vp)
            {
                ans.push_back(it.second);
            }
            return ans;
        }
};