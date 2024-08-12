//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    int mod=1e9+7;
    vector<int>dp;
        int solve(int i,string str)
        {
            if(i==str.size()) return 1;
            if(str[i]=='0') return 0;
            if(dp[i]!=-1) return dp[i];
            int ans=solve(i+1,str)%mod;
            if(str[i]>='1' && i+1<str.size() && str[i]<='2'){
                if(str[i]=='1'){
                    ans=(ans+solve(i+2,str))%mod;
                }else if(str[i+1]<='6'){
                    ans=(ans+solve(i+2,str))%mod;
                }
            }
            return dp[i]=ans;
        }
	public:
		int CountWays(string str){
		    dp.resize(str.size(),-1);
		    int ans=solve(0,str);
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends