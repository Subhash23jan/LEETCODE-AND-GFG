class Solution
{
    public:
        vector<int> sortByBits(vector<int> &arr)
        {
            vector<pair<int, int>> vp;
            for (auto it: arr)
            {
                int n = it;
                int cnt = 0;
                while (n)
                {
                    if (n % 2 != 0)
                        cnt++;
                    n = n >> 1;
                }
                vp.push_back({cnt, it});
            }
            sort(vp.begin(), vp.end(), [](pair<int, int> p1, pair<int, int> p2)
            {
                return p1 < p2;
	});
            vector<int> ans;
            for (auto it: vp)
            {
                ans.push_back(it.second);
            }
            return ans;
        }
};