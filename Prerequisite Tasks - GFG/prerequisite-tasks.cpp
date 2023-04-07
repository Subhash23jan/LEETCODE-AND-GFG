//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	   vector<int>adj[N];
	   vector<int>indegree(N,0);
	   int cnt=0;
	   for(auto it:prerequisites)
	   {
	       indegree[it.first]++;
	       adj[it.second].push_back(it.first);
	   }
	   queue<int>q;
	   for(int i=0;i<N;i++)
	   {
	       if(!indegree[i])
	       {
	           q.push(i);
	       }
	   }
	   while(q.size())
	   {
	       int node=q.front();
	       cnt++;
	       q.pop();
	       for(auto it:adj[node])
	       {
	           if(!--indegree[it])
	           {
	               q.push(it);
	           }
	       }
	   }
	   return cnt==N;
	   
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends