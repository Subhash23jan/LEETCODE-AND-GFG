#define pr pair<int,int> 
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        for(auto it:times)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pr,vector<pr>,greater<pr>>pq;
        pq.push({0,k});
        vector<int>vis(n+1,0);
        vector<int>dis(n+1,INT_MAX);
        dis[k]=0;
        while(pq.size())
        {
            auto top=pq.top();
            pq.pop();
            int delay=top.first;
            int node=top.second;
            vis[node]=1;
            for(auto it:adj[node])
            {
                int adjNode=it.first;
                int time=it.second;
                if(!vis[adjNode] && dis[adjNode]>=time+delay)
                {
                    dis[adjNode]=time+delay;
                    pq.push({dis[adjNode],adjNode});
                }
            }

        }
        int  ans=0;
        for(int i=1;i<=n;i++)
        {
            if(dis[i]==INT_MAX) return -1;
            ans=max(ans,dis[i]);
        }
        return ans;
    }
};