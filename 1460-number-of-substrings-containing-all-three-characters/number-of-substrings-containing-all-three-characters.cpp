class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        long long totalSubstrings=1LL*(n)*(n+1)/2;
        int l=0,r=0;
        long long cnt=0;
        unordered_map<char,int>mp;
        while(r<n)
        {
            mp[s[r]]++;
            while(mp.size()==3){
                if(--mp[s[l]]==0){
                    mp.erase(s[l]);
                }
                l++;
            }
            cnt+=(r-l+1);
            r++;
        }
        return totalSubstrings-cnt;
    }
};