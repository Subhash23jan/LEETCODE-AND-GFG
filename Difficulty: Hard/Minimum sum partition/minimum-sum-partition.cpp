//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    vector<vector<int>>dp;
    int solve(int i,long long currSum,int arr[],int n,int totalSum)
    {
        if(i==n || currSum>=(totalSum/2))
        {
            return abs(totalSum-2*currSum);
        }
        if(dp[i][currSum]!=-1) return dp[i][currSum];
        return dp[i][currSum]=min(solve(i+1,currSum,arr,n,totalSum),solve(i+1,currSum+arr[i],arr,n,totalSum));
    }
  public:
	int minDifference(int arr[], int n)  { 
	    long long sum=0;
	    for(int i=0;i<n;i++)
	    {
	        sum+=arr[i];
	    }
	    dp.resize(n+1,vector<int>(sum/2,-1));
	    return solve(0,0,arr,n,sum);
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends