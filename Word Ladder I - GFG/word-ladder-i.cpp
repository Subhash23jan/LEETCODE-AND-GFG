//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
    
private:

bool oneletter(string s1, string s2)
{
    int cnt = 0; int len = s1.size();
    int idx = 0;
    while(idx < len)
    {
        if(s1[idx] != s2[idx])
        {
            cnt++;
        }
        if(cnt > 1) return false;
        idx++;
    }
    return true;
}
public:
    int wordLadderLength(string start, string target, vector<string>& wordlist) {
        unordered_map<string, vector<string>> mp;
        unordered_map<string, bool> vis;
        int len = start.size();
        vis[start] = true;
        for(auto& str : wordlist)
        {
            if(str != start)
            {
                vis[str] = false;
                if(oneletter(str, start) == true)
                {
                    mp[str].push_back(start);
                    mp[start].push_back(str);
                }
            }
        }
        for(auto& str1 : wordlist)
        {
            for(auto& str2 : wordlist)
            {
                if(str1!=start && str2!=start && str1 != str2)
                {
                    if(oneletter(str1, str2) == true)
                    {
                        mp[str1].push_back(str2);
                        
                    }
                }
            }
        }
        
        queue<pair<string, int>> q;
        
        q.push({start, 1});
        while(!q.empty())
        {
            auto src = q.front().first;
            int level = q.front().second;
            q.pop();
            
            //cout<<src<<endl;
            
            if(src == target) return level;
            
            auto vec = mp[src];
            
            for(auto& str : vec)
            {
                if(!vis[str])
                {
                    vis[str] = true;
                    q.push({str, level+1});
                }
            }
        }
        
        
        return 0;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends