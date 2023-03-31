//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    int cnt=0;
	    vector<int>freq1(26,0),freq2(26,0);
	    for(auto it:pat)
	    {
	        freq1[it-'a']++;
	    }
	    int i=0,j=0;
	    while(i<txt.size() && j<txt.size())
	    {
	       freq2[txt[i++]-'a']++;
	       while(freq2[txt[j]-'a']>freq1[txt[j]-'a'])
	       {
	           freq2[txt[j]-'a']--;
	           j++;
	       }
	        if(freq1==freq2)
	          cnt++;
	    }
	    return cnt;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends