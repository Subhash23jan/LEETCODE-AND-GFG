class Solution
{
    vector<vector < int>> buildGraph(vector<vector < int>> &edges)
    {
        int n = edges.size();
        vector<vector < int>> graph(n + 1);
        for (auto &it: edges)
        {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        return graph;
    }

    int maxDiameter(int parent, int node, vector<vector < int>> &adj, int &diameter)
    {
        int mx1 = 0, mx2 = 0;
        for (auto it: adj[node])
        {
            if (it != parent)
            {
                int temp = 1 + maxDiameter(node, it, adj, diameter);
                if (mx1 < temp)
                {
                    mx2 = mx1;
                    mx1 = temp;
                }
                else if (mx2 < temp)
                {
                    mx2 = temp;
                }
            }
        }
        diameter = max(diameter, mx1 + mx2);
        return mx1;
    }

    public:
        int minimumDiameterAfterMerge(vector<vector < int>> &edges1, vector< vector< int>> &edges2)
        {
            vector<vector < int>> adj1 = buildGraph(edges1);
            vector<vector < int>> adj2 = buildGraph(edges2);
            int diameter1 = 0, diameter2 = 0;
            maxDiameter(-1, 0, adj1, diameter1);
            maxDiameter(-1, 0, adj2, diameter2);
            cout << diameter1 << endl;
            cout << diameter2 << endl;
            return max({ diameter1,
                diameter2,
                (diameter1 + 1) / 2 + (diameter2 + 1) / 2 + 1 });
        }
};