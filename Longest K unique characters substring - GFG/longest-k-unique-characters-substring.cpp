//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    int atmost(string s,int k)
    {
        map<char,int>mp;
        int i=0,j=0,cnt=0;
        while(j<s.size())
        {
            mp[s[j++]]++;
            while(mp.size()>k)
            {
                if(--mp[s[i]]==0)
                {
                    mp.erase(s[i]);
                }
                i++;
            }
            if(mp.size()==k)
            cnt=max(cnt,j-i);
        }
        return cnt;
    }
  public:
    int longestKSubstr(string s, int k) {
        
       int ans=atmost(s,k);
       return ans?ans:-1;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends