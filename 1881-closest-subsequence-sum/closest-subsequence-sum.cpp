class Solution
{
    void solve(int i, int n, int sum, const vector<int> &nums, vector<int> &vec)
    {
        if (i == n)
        {
            vec.push_back(sum);
            return;
        }
        solve(i + 1, n, sum, nums, vec);
        solve(i + 1, n, sum + nums[i], nums, vec);
    }

    public:
        int minAbsDifference(vector<int> &nums, int goal)
        {
            int n = nums.size();
            vector<int> left, right;

            solve(0, n / 2, 0, nums, left);
            solve(n / 2, n, 0, nums, right);

            sort(left.begin(), left.end());
            sort(right.begin(), right.end());

            int ans = abs(goal);
            for (auto val: left)
            {
                int need = goal - val;

                auto itr = lower_bound(right.begin(), right.end(), need);

                if (itr != right.end())
                {
                    ans = min(ans, abs(goal - (val + *itr)));
                }

                if (itr != right.begin())
                {
                    itr--;
                    ans = min(ans, abs(goal - (val + *itr)));
                }
            }
            return ans;
        }
};