class Solution
{
    public:
        double maxProbability(int n, vector<vector < int>> &edges, vector< double > &succProb, int start, int end)
        {
            vector<pair<int, double>> adj[n];
            priority_queue<pair<double, int>> pq;
            pq.push({ (double) 1,
                start });
            for (int i = 0; i < edges.size(); i++)
            {
                int u = edges[i][0];
                int v = edges[i][1];
                adj[u].push_back({ v,
                    succProb[i] });
                adj[v].push_back({ u,
                    succProb[i] });
            }
          //  vector<int> visited(n, 0);
            vector<double> ans(n, 0);
            while (pq.size())
            {
                auto it = pq.top();
                pq.pop();
                int node = it.second;
                double prob = it.first;
                for (auto it: adj[node])
                {
                    if (ans[it.first] < (double)(prob *it.second))
                    {
                        ans[it.first] = prob *it.second;
                        pq.push({ ans[it.first],
                            it.first });
                    }
                }
            }
            return ans[end];
        }
};