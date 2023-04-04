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
        while(j<n && i<n)
        {
            if(arr[j]=='T')
            {
                j++;
            }else
            {
                if(arr[i]=='P')
                {
                    i++;
                }else
                {
                    if(abs(j-i)<=k)
                    {
                        cnt++;
                        j++;
                        i++;
                    }else{
                        if(j>i)
                        {
                            i++;
                        }else
                        {
                            j++;
                        }
                    }
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