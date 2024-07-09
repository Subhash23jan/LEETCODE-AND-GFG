class Solution
{
    public:
        int carFleet(int target, vector<int> &position, vector<int> &speed)
        {
            vector<pair<int, double>> v;
            int n = position.size();
            for (int i = 0; i < n; i++)
            {
                double t = double(target - position[i]) / (double) speed[i];

                v.push_back({ position[i],
                    t });
            }
            sort(v.begin(), v.end());

            int ans = 0;
            double mxTime = 0;
            for (int i = n - 1; i >= 0; i--)
            {
                if (v[i].second > mxTime)
                {
                    mxTime = v[i].second;
                    ans++;
                }
            }
            return ans;
        }
};