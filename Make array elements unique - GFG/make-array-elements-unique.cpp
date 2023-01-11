//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int minIncrements(vector<int> arr, int N) {
        priority_queue<int,vector<int>,greater<int>>pq;
        long long int ans=0;
        for(auto it:arr)
        pq.push(it);
        while(!pq.empty())
        {
            int top=pq.top();
            pq.pop();
            if(!pq.empty() && pq.top()==top)
            {
                ans++;
                pq.push(top+1);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minIncrements(arr, N) << endl;
    }
}
// } Driver Code Ends