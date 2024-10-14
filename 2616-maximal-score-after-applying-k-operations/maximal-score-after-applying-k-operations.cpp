class Solution
{
    public:
        long long maxKelements(vector<int> &nums, int k)
        {
            priority_queue<long> pq;
            for (auto it: nums)
                pq.push(it);
            long long ans = 0;
            int i = 0;
            while (i < k)
            {
                long long num = pq.top();
                pq.pop();
                ans += num;
                int temp = ceil((double)num / 3);
                cout<<temp<<endl;
                pq.push(temp);
                i++;
            }
            return ans;
        }
};