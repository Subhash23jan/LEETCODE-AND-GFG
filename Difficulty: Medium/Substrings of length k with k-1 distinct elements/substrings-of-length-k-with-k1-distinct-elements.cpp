//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int countOfSubstrings(string s, int k) {
       // bool flag=false;
        int ans=0,l=0,r=0;
        unordered_map<char,int>mp;
        while(r<s.size())
        {
            mp[s[r]]++;
            if((r-l+1)>k)
            {
                if(--mp[s[l]]==0){
                    mp.erase(s[l]);
                }
                l++;
            }
            if((r-l+1)==k && mp.size()==k-1){
                ans++;
            }
            r++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        int K;
        cin>>S;
        cin>>K;

        Solution ob;
        cout << ob.countOfSubstrings(S,K) << endl;
    }
    return 0;
}
// } Driver Code Ends