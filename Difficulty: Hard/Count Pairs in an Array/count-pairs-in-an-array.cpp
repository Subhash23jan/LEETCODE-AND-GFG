//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int countPairs(int arr[] , int n ) 
    {
        std::vector<long long> vec;
        int ans = 0;
        for(int i = n - 1; i >= 0; --i)
        {
            long long prod = static_cast<long long>(i) * arr[i];
            int cnt = 0;
            if (!vec.empty()) 
            {
                cnt = std::lower_bound(vec.begin(), vec.end(), prod) - vec.begin();
            }
            ans += cnt;
            vec.insert(lower_bound(vec.begin(), vec.end(), prod), prod);
        }
        return ans;
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	Solution ob;
    	cout<<ob.countPairs(a, n)<<endl;
    }
}
// } Driver Code Ends