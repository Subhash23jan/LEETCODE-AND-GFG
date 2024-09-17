class Solution {
public:
    bool check(vector<int>&dp, int k){
        for(int i=0;i<26;i++){
            if(dp[i]==0) continue;
            else if(dp[i]!=k){
                return false;
            }
        }
        return true;
    }
    long long calculate(string &s, int k){

        int n = s.size();
        long long ans=0;

        for(int i=1;i<=26;i++){
            int len = k*i;
            if(len>n) break;
            vector<int>dp(26,0);

            for(int j=0;j<n;j++){
                dp[s[j]-'a']++;
                if((j+1)>=len){
                    if(check(dp,k)){
                        ans++;
                    }
                    dp[s[j+1-len]-'a']--;
                }
            }
        }
        return ans;
    }
    int countCompleteSubstrings(string word, int k) {
        
        int n = word.size();
        long long ans = 0;
        string curr = "";
        for(int i=0;i<n;i++){
            
            curr.push_back(word[i]);
            if(i<=n-2 and abs(word[i]-word[i+1])>2){
                ans+= calculate(curr, k);
                curr="";
            }
        }
        ans+= calculate(curr, k);        
        return ans;
    }
};