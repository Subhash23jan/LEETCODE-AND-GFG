class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int ans=w;
        vector<pair<int,int>>vp;
        int n=capital.size();
        for(int i=0;i<n;i++)
        {
            vp.push_back({capital[i],profits[i]});
        }
        sort(vp.begin(),vp.end());
        priority_queue<int>pq;
        int index=0;
        while(k){
            while(index<n && vp[index].first<=ans){
                pq.push(vp[index].second);
                index++;
            }
            if(pq.size()){
                k--;
            auto top=pq.top();
            pq.pop();
            ans+=top;
            }else{
                return ans;
            }
        }
        return ans;
    }
};