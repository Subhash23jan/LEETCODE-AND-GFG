//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int findMinCost(string x, string y, int costX, int costY) {
        int m = x.size();
        int n = y.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        // Base cases
        for (int i = 0; i <= m; ++i) {
            dp[i][n] = (m - i) * costX;
        }
        for (int j = 0; j <= n; ++j) {
            dp[m][j] = (n - j) * costY;
        }
        

        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (x[i] == y[j]) {
                    dp[i][j] = dp[i + 1][j + 1];
                } else {
                    dp[i][j] = min(costX + dp[i + 1][j], costY + dp[i][j + 1]);
                }
            }
        }
        
        return dp[0][0];
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;

        int costX, costY;
        cin >> costX >> costY;

        Solution ob;
        cout << ob.findMinCost(x, y, costX, costY);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends