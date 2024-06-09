//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int catchThieves(char arr[], int n, int k) 
    {
        int i=0,j=0;
        int cnt=0;
        while(i<n && j<n)
        {
            while(i<n && arr[i]=='P') i++;
            while(j<n && arr[j]=='T') j++;
            if(i<n && j<n && abs(i-j)<=k){
                cnt++;
                i++;
                j++;
            }else{
                if(i>j){
                    j++;
                }else{
                    i++;
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n, k;
		cin>>n >> k;
		char arr[n];
		for (int i = 0; i < n; ++i)
			cin>>arr[i];
		Solution obj;
		cout<<obj.catchThieves(arr, n, k) << endl;
	}
	return 0; 
} 


// } Driver Code Ends