class Solution
{
    public:
        int numFactoredBinaryTrees(vector<int> arr)
        {
            map<int, long long int > mp;
            for (int ele: arr)
            {
                mp[ele] = 1;
            }
            sort(arr.begin(), arr.end());
            for (int i = 1; i < arr.size(); i++)
            {
                long long int count = 0;
                for (int j = 0; j < i; j++)
                {
                    if (arr[i] % arr[j] == 0)
                    {
                        auto it = mp.find(arr[i] / arr[j]);
                        if (it != mp.end())
                        {
                            count += (mp[arr[j]] *it->second);
                        }
                    }
                }
                mp[arr[i]] += count;
            }
            long long int ans = 0;
            for (auto it: mp)
            {
                ans += it.second;
            }
            return (ans % 1000000007);
        }
};