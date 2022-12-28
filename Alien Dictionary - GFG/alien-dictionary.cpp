//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    private:
    void dfs(int node,vector<int>adj[],stack<int>&st,vector<int>&vis)
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            dfs(it,adj,st,vis);
        }
        st.push(node);
        return;
    }
    vector<int>toposort(int V,vector<int>adj[])
    {
        vector<int>vis(V,0);
        stack<int>st;
        vector<int>ans;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            dfs(i,adj,st,vis);
        }
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
    public:
    string findOrder(string dict[], int N, int K) {
        vector<int>adj[K];
        for(int i=0;i<N-1;i++)
        {
            string str1=dict[i];
            string str2=dict[i+1];
            int len=min(str1.size(),str2.size());
            for(int  i=0;i<len;i++)
            {
                if(str1[i]!=str2[i])
                {
                    adj[str1[i]-'a'].push_back(str2[i]-'a');
                    break;
                }
            }
        }
        vector<int>ans=toposort(K,adj);
        string str;
        for(auto it:ans)
        {
            str+=it+'a';
        }
        return str;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends