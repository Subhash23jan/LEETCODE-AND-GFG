class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>>vp;
        for(int i=0;i<mat.size();i++)
        {
            int cnt=0;
            for(int j=0;j<mat[i].size();j++)
            {
                if(mat[i][j]==0)
                break;
                cnt++;
            }
            vp.push_back({cnt,i});
        }
        sort(vp.begin(),vp.end(),[](pair<int,int>p1,pair<int,int>p2){
            if(p1.first==p2.first)
            return p1.second<p2.second;
            return p1.first<p2.first;
        });
        vector<int>ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(vp[i].second);
        }
        return ans;
    }
};