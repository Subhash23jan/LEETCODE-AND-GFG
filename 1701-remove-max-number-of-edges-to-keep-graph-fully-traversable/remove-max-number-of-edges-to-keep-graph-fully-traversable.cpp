class Union
{
    public:
        vector<int> parent;
    vector<int> rank;
    int size;
    Union(int n)
    {
        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
        this->size = n;
    }
    void addEdge(int u, int v)
    {
        int up = findParent(u);
        int vp = findParent(v);
        if (up == vp) return;
        if (rank[up] > rank[vp])
        {
            rank[up] += rank[vp];
            parent[vp] = parent[up];
        }
        else
        {
            rank[vp] += rank[up];
            parent[up] = parent[vp];
        }
    }
    int findParent(int i)
    {
        return parent[i] = parent[i] == i ? i : findParent(parent[i]);
    }
    bool canTraverse()
    {
        for (int i = 1; i < size; i++)
        {
            int p = findParent(i);
            cout << p << " " << parent[i] << endl;
            if (p != parent[1])
            {
                return false;
            }
        }
        return true;
    }
};
class Solution
{
    public:
        int maxNumEdgesToRemove(int n, vector<vector < int>> &edges)
        {
            sort(edges.rbegin(), edges.rend());
            Union alice = Union(n + 1), bob = Union(n + 1);
            int cnt = 0;
            for (auto it: edges)
            {
                int type = it[0];
                int u = it[1];
                int v = it[2];
                if (type == 3)
                {
                    int up = alice.findParent(u);
                    int vp = alice.findParent(v);
                    int up1 = bob.findParent(u);
                    int vp1 = bob.findParent(v);
                    if (up == vp && up1 == vp1)
                    {

                        cnt++;
                    }
                    else
                    {
                        alice.addEdge(u, v);
                        bob.addEdge(u, v);
                    }
                }
                else if (type == 1)
                {
                    int up = alice.findParent(u);
                    int vp = alice.findParent(v);
                    if (up == vp)
                    {
                        cnt++;
                    }
                    else
                    {
                        alice.addEdge(u, v);
                    }
                }
                else
                {
                    int up = bob.findParent(u);
                    int vp = bob.findParent(v);
                    if (up == vp)
                    {
                        cnt++;
                    }
                    else
                    {
                        bob.addEdge(u, v);
                    }
                }
            }
            return (alice.canTraverse() && bob.canTraverse()) ? cnt : -1;
        }
};