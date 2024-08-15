class Solution {
public:
    string smallestSubsequence(string s) {
        map<char,int>mp;
        for(auto it:s)
        {
            mp[it]++;
        }
        stack<char>st;
        vector<int>vis(26,0);
        for(auto it:s)
        {
            mp[it]--;
            if(vis[it-'a'])continue;
            while(st.size() && mp[st.top()]>=1 && st.top()>it ){
                vis[st.top()-'a']--;
                st.pop();      
            }
            vis[it-'a']++;
            st.push(it);
        }
        string str="";
        while(st.size())
        {
            str+=st.top();
            st.pop();
        }
        reverse(str.begin(),str.end());
        return str;
    }
};