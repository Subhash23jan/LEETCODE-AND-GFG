class Solution {
public:
    string clearDigits(string s) {
         stack<char>st;
         for(int i=0;i<s.size();i++)
         {
             if(s[i]>='0' && s[i]<='9'){
                 st.pop();
             }else{
                 st.push(s[i]);
             }
         }
        string str="";
        while(st.size()){
            str+=st.top();
            st.pop();
        }
        reverse(str.begin(),str.end());
        return str;
    }
};