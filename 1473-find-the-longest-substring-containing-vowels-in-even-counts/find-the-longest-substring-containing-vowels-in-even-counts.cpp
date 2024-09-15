class Solution {
private:
    bool isVowel(char ch)
    {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
public:
    int findTheLongestSubstring(string s) {
        unordered_map<char,int>mp,freq;
        mp['a']=1;
        mp['e']=2;
        mp['i']=3;
        mp['o']=4;
        mp['u']=5;
        int mask=0;
        unordered_map<int,int>dp;
        dp[0]=-1;
        int ans=0,n=s.size();
        for(int i=0;i<n;i++)
        {
            freq[s[i]]++;
            if(isVowel(s[i])){
                int num=mp[s[i]];
                if(freq[s[i]]%2!=0){
                    mask=(mask|(1<<num));
                }else{
                    mask=(mask^(1<<num));
                }
            }
            if(!dp.count(mask)){
                dp[mask]=i;
            }else{
                ans=max(ans,i-dp[mask]);
            }
        }
        return ans;
    }
};