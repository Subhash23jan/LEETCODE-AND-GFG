class Solution
{
    public:
        int secondMinimum(int n, vector<vector < int>> &edges, int time, int change)
        {
            vector<int> dis(n + 1, -1), vis(n + 1, 0);
            vector<vector < int>> adj(n + 1);
            for (auto it: edges)
            {
                adj[it[0]].push_back(it[1]);
                adj[it[1]].push_back(it[0]);
            }
            priority_queue<pair<int, int>, vector< pair<int, int>>, greater<pair<int, int>>> pq;
            pq.push({ 0,
                1 });
            while (!pq.empty())
            {
                auto[currTime, node] = pq.top();
                pq.pop();
                if (dis[node] == currTime || vis[node] >= 2) continue;
                vis[node]++;
                dis[node] = currTime;
                if (node == n && vis[node] == 2) return currTime;
                if ((currTime / change) % 2 != 0)
                {
                    currTime = (currTime / change + 1) *change;
                }
                for (auto next: adj[node])
                {
                    pq.push({ currTime + time,
                        next });
                }
            }
            return 0;
        }
};