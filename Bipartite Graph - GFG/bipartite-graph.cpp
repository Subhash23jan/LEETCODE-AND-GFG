//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    bool isTrue(vector<int>&color,int node,vector<int>adj[],int pNodeColor)
    {
        color[node]=pNodeColor;
        bool flag=true;
        for(auto it:adj[node])
        {
            if(color[it]==-1)
            {
                flag&=isTrue(color,it,adj,!pNodeColor);
            }else if(color[it]==color[node])
            return false;
        }
        return flag;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int>color(V,-1);
	    for(int i=0;i<V;i++)
	    {
	        
	        if(color[i]==-1)
	        {
	            if(!isTrue(color,i,adj,0))
	            return false;
	        }
	        
	    }
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends