class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int>mp;
        for(auto it:word)
        {
            mp[it]++;
        }
        priority_queue<int>pq;
        for(auto it:mp){
            pq.push(it.second);
        }
        int ans=0;
        while(pq.size())
        {
            for(int j=1;j<=4;j++)
            {
                for(int i=0;i<8 && pq.size();i++)
                {
                    ans+=(pq.top()*j);
                    pq.pop();
                }
            }
        }
        return ans;
    }
};