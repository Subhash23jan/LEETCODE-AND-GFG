//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    long long reversedBits(long long x) {
        long long y=0;
        for(int bit=0;bit<32;bit++){
            if(x & (1 << bit)){
                y|=((long long)1 << (31-bit));
            }
        }
        return y;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends