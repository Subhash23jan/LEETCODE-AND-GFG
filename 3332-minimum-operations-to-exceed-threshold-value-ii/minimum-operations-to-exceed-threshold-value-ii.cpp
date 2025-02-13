class Solution
{
    public:
        int minOperations(vector<int> &nums, int k)
        {
            priority_queue < long long, vector < long long >, greater < long long>> pq;
            for (auto it: nums)
            {
                pq.push(it);
            }
            int cnt = 0;
            while (pq.size() > 1)
            {
                auto num1 = pq.top();
                pq.pop();
                auto num2 = pq.top();
                pq.pop();
                if (num1 >= k) return cnt;
                pq.push(min(num1, num2) *2 + max(num1, num2));
                cnt++;
            }
            return cnt;
        }
};