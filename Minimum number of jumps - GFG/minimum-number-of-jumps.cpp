//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
       int step=0;
       int currentIndex=0,maxIndex=0;
       for(int i=0;i<n-1;i++)
       {
           maxIndex=max(maxIndex,i+arr[i]);
           if(i==currentIndex)
           {
               step++;
               currentIndex=maxIndex;
           }
       }
       return currentIndex>=n-1?step:-1;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends