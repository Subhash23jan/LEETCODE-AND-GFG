//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        map<char,int>mp1,mp2;
        for(auto it:str)
        mp1[it]++;
        int i=0,j=0;
        int len=INT_MAX;
        while(j<str.size())
        {
            mp2[str[j++]]++;
            while(mp2[str[i]]>1)
            {
                mp2[str[i++]]--;
            }
            if(mp2.size()==mp1.size())
            {
                len=min(len,j-i);
            }
        }
        return len;
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends