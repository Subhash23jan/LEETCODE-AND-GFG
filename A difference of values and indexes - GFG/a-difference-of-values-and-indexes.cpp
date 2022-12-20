//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 



// } Driver Code Ends
class Solution{
  public:
    int maxDistance(int arr[], int n) 
    { 
       int maxInd=INT_MIN,maxVal=INT_MIN;
       int minInd=INT_MAX,minVal=INT_MAX;
       for(int i=0;i<n;i++)
       {
           maxInd=max(maxInd,arr[i]-i);
           maxVal=max(maxVal,arr[i]+i);
           minInd=min(minInd,arr[i]-i);
           minVal=min(minVal,arr[i]+i);
           
       }
       return max(maxInd-minInd,maxVal-minVal);
    } 
};

//{ Driver Code Starts.
int main() 
{ 
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i = 0; i<n; i++)
	        cin>>arr[i];
	    Solution obj;
	    cout<<obj.maxDistance(arr, n)<<endl;
	}
} 

// } Driver Code Ends