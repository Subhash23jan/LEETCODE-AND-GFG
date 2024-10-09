class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        int cnt=0;
        for(auto it:s)
        {
            if(it=='('){
                st.push(it);
            }else{
                if(st.size()) st.pop();
                else cnt++;
            }
        }
        return cnt+st.size();
    }
};