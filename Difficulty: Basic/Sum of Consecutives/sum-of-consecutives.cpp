//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int canBeSumofConsec(long long int n) { 
        long long ans=(n&(n-1));
        return ans!=0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.canBeSumofConsec(n) << endl;
    }
    return 0;
}

// } Driver Code Ends