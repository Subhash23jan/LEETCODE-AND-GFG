class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        string ans="";
        for(auto it:num){
            while(st.size() && st.top()>it && k){
                st.pop();
                k--;
            }
            st.push(it);
        }
        while(k--){
            st.pop();
        }
        while(st.size()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        while(ans.size() && ans[0]=='0'){
            ans=ans.substr(1);
        }
        if(ans.size()==0)return "0";
        return ans;
    }
};