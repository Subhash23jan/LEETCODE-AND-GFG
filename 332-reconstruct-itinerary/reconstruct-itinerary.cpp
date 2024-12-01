class Solution
{
    unordered_map<string, multiset < string>> adj;
    vector<string> ans;

    void postOrder(string node)
    {
        while (!adj[node].empty())
        {
            string child = *adj[node].begin();
            adj[node].erase(adj[node].begin());
            postOrder(child);
        }
        ans.push_back(node);
    }

    public:
        vector<string> findItinerary(vector<vector < string>> &tickets)
        {
            for (auto it: tickets)
            {
                adj[it[0]].insert(it[1]);
            }
            postOrder("JFK");
            reverse(ans.begin(), ans.end());
            return ans;
        }
};