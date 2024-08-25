//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    private:
    int solve(int m, int n, vector<vector<int>> &dp){
	    if(m == n) return 1;
	    if(m < 0 || n < 0) return INT_MAX;
	    if(dp[m][n] != -1) return dp[m][n];
	    int temp1 = INT_MAX;
	    for(int i = 1;i<m;i++){
	        temp1 = min(temp1, solve(i, n, dp) + solve(m-i, n, dp));
	    }
	    int temp2 = INT_MAX;
	    for(int i = 1;i<n;i++){
	        temp2 = min(temp2, solve(m, i, dp) + solve(m, n- i, dp));
	    }
	    return  dp[m][n] = min(temp1, temp2);
	}
public:
	int minCut(int M, int N)
	{
	   vector<vector<int>> dp(M+1, vector<int> (N+1, -1));
       return solve(M, N, dp);
	}
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;

	    

	    Solution ob;
	    cout << ob.minCut(m, n) << "\n";

	     
    }
    return 0;
}

// } Driver Code Ends