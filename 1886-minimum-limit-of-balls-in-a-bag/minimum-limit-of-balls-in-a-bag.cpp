class Solution
{
    bool solve(int mx, vector<int> &nums, int maxOperations)
    {
        priority_queue<int> pq;
        for (auto it: nums) pq.push(it);
        while (maxOperations)
        {
            int top = pq.top();
            pq.pop();
            if (top <= mx) return true;
            int need = ((top + mx - 1) / mx)-1;
            if (need > maxOperations) return false;
            maxOperations -= need;
            pq.push(mx);
        }
        return pq.top() <= mx;
    }
    public:
        int minimumSize(vector<int> &nums, int maxOperations)
        {
            int n = nums.size(), ans = 1;
            int l = 1, r = *max_element(nums.begin(), nums.end());
            while (l <= r)
            {
                int mid = (l + r) / 2;
                cout<<mid<<endl;
                if (solve(mid, nums, maxOperations))
                {
                    ans = mid;
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            return ans;
        }
};