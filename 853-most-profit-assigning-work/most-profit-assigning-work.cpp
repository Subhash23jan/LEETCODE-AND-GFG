class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> vp;
        int n = profit.size();
        for (int i = 0; i < n; i++) {
            vp.push_back({difficulty[i], profit[i]});
        }
        sort(vp.begin(), vp.end());
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                mp[vp[i].first] = vp[i].second;
            } else {
                mp[vp[i].first] = max(vp[i].second, mp[vp[i-1].first]);
            }
        }
        sort(worker.begin(), worker.end());
        int index = worker.size()-1;
        auto it = mp.end();
        int ans = 0;
        while (it != mp.begin()) {
            --it;
            while (index >=0 && worker[index] >= it->first) {
                ans += it->second;
                index--;
            }
        }
        return ans;
    }
};
