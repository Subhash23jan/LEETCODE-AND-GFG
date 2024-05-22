class Solution {
    bool isPlaindrome(string str){
        int n=str.size();
        int i=0,j=n-1;
        while(i<j && str[i]==str[j]){
            i++;
            j--;
        }
        return i>=j;
    }
    void solve(int i,string s,vector<string>temp,vector<vector<string>>&ans){
        if(i==s.size()){
            ans.push_back(temp);
            return;
        }
        string str="";
        for(int index=i;index<s.size();index++)
        {
            str+=s[index];
            if(isPlaindrome(str)){
                temp.push_back(str);
                solve(index+1,s,temp,ans);
                temp.pop_back();
            }
        }
        return;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        solve(0,s,temp,ans);
        return ans;
    }
};