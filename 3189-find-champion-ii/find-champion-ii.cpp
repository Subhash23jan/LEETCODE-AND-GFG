class Solution
{
    public:
        int findChampion(int n, vector<vector < int>> &edges)
        {
            vector<int> counter(n, 0);
            for (auto it: edges)
            {
                counter[it[1]]++;
            }
            int cnt = 0, ans;
            for (int i = 0; i < n; i++)
            {
                if (counter[i] == 0)
                {
                    ans = i;
                    cnt++;
                }
            }
            return cnt == 1 ? ans : -1;
        }
};