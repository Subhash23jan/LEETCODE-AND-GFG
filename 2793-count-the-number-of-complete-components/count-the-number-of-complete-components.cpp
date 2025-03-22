class Union
{
    public:
        vector<int> parent;
    vector<int> size;
    Union(int n)
    {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    void add(int u, int v)
    {
        int up = getParent(u);
        int vp = getParent(v);
        if (up == vp) return;
        if (up > vp)
        {
            swap(up, vp);
        }
        parent[up] = vp;
        size[vp] += size[up];
    }
    int getSize(int u)
    {
        return size[getParent(u)];
    }
    int getParent(int u)
    {
        if (parent[u] == u) return u;
        return parent[u] = getParent(parent[u]);
    }
};
class Solution
{
    public:
        int countCompleteComponents(int n, vector<vector < int>> &edges)
        {
            Union obj(n);
            unordered_map<int, int> mp;
            unordered_map<int, vector < int>> adj;
            for (auto it: edges)
            {
                obj.add(it[0], it[1]);
                mp[it[0]]++;
                mp[it[1]]++;
            }
            vector<int> vis(n, 0);

            for (int i = 0; i < n; i++)
            {
                int p = obj.getParent(i);
                adj[p].push_back(i);
            }
            int ans = 0;
            for (int i = 0; i < n; i++)
            {
                int p = obj.getParent(i);
                if (vis[p]) continue;
                int size = obj.getSize(p);
                cout << p << " " << size << endl;
                bool flag = true;
                for (auto it: adj[p])
                {
                    if (mp[it] != (size-1))
                    {
                        flag = false;
                        break;
                    }
                }
                ans += (flag);
                vis[p]++;
            }

            return ans;
        }
};