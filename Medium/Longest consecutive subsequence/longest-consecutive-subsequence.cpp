//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      unordered_map<int,int>mp;
      
      for(int i=0;i<N;i++)
      {
          mp[arr[i]]++;
      }
      int ans=0,cnt=0;
      for(int i=0;i<N;i++)
      {
          if(mp.count(arr[i]-1)){
              continue;
          }
          cnt=0;
          int val=arr[i];
          while(mp.count(val)){
              cnt++;
              val++;
          }
          ans=max(ans,cnt);
      }
      return ans;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends