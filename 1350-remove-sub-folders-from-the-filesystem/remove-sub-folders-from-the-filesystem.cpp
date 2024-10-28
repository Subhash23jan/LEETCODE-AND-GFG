class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_map<string, int> mp;
        sort(folder.begin(), folder.end(),
             [](string s1, string s2) { return s1.size() < s2.size(); });
        for (auto it : folder) {
            string str = "";
            bool found = false;
            for (char ch : it) {
                if (ch == '/') {
                    if (mp.count(str)) {
                        found = true;
                        break;
                    }
                    str += ch;
                } else {
                    str += ch;
                }
            }
            if (!found) {
                mp[it]++;
            }
        }
        vector<string> ans;
        for (auto it : mp) {
            ans.push_back(it.first);
        }
        return ans;
    }
};