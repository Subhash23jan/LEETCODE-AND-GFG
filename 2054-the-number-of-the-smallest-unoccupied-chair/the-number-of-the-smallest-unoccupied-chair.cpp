class Solution
{
public:
    int smallestChair(vector<vector<int>> &times, int targetFriend)
    {
        int targetArrival = times[targetFriend][0];
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        set<int> st;
        sort(times.begin(), times.end());
        int n = times.size();
        for (int i = 0; i < n; i++)
        {
            st.insert(i);
        }

        for (auto &it : times)
        {
            int arrival = it[0], leave = it[1];
            while (!pq.empty() && pq.top().first <= arrival)
            {
                st.insert(pq.top().second);
                pq.pop();
            }

            int chair = *st.begin();
            st.erase(st.begin());
            pq.push({leave, chair});

            if (arrival == targetArrival) 
                return chair;
        }
        return -1;
    }
};
