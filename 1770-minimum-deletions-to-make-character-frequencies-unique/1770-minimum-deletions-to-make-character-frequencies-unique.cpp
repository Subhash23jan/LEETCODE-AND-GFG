class Solution
{
    public:
        int minDeletions(string s)
        {
            map<char, int> mp;
            for (auto it: s)
                mp[it]++;
            priority_queue<int> pq;
            for (auto it: mp)
                pq.push(it.second);
            int top = pq.top();
            pq.pop();
            int cnt = 0;
            while (!pq.empty())
            {
                int temp = pq.top();
                pq.pop();
                if(temp == top)
                {
                    temp--;
                    cnt++;
                    if(temp!=0)
                    pq.push(temp);
                }else{
                    top=temp;
                }
                
            }
            return cnt;
        }
};