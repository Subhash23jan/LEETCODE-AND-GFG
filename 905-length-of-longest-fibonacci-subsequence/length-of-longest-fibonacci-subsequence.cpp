class Solution
{
    public:

        int help(int i, int j, unordered_map<int, int> &mp, vector<int> &arr)
        {
            int n = arr.size();
            if (j >= n) return 0;

            int nxt = arr[i] + arr[j];
            if (mp.find(nxt) != mp.end())
            {
                int ind = mp[nxt];
                return 1 + help(j, ind, mp, arr);
            }
            return 0;
        }

    int lenLongestFibSubseq(vector<int> &arr)
    {
        int n = arr.size();
        int ans = 0;

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            mp[arr[i]] = i;
        }

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int temp = help(i, j, mp, arr);
                if (temp > 0) temp += 2;
                if (temp > ans) ans = temp;
            }
        }
        return ans;
    }
};
