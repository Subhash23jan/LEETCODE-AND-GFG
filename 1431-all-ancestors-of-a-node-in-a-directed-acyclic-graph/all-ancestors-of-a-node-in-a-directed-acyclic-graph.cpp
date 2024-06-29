class Solution
{
    void bfs(int n,int node, vector<int> adj[], vector<int> &vec)
    {
        vector<int> vis(n, 0);
        queue<int> q;
        q.push(node);
        while (!q.empty())
        {
            int tp = q.front();
            q.pop();
            if (tp != node && !vis[tp])
            {
                vec.push_back(tp);
            }
            vis[tp] = 1;
           
            for (auto it: adj[tp])
            {
                
                if (!vis[it])
                {
                    q.push(it);
                }
            }
        }
        sort(vec.begin(), vec.end());
    }
    public:
        vector<vector < int>> getAncestors(int n, vector<vector < int>> &edges)
        {
            vector<vector < int>> ans;
            vector<int> adj[n];
            for (auto it: edges)
            {
                adj[it[1]].push_back(it[0]);
            }
            for (int i = 0; i < n; i++)
            {
                vector<int> vec;
                bfs(n,i, adj, vec);
                ans.push_back(vec);
            }
            return ans;
        }
};