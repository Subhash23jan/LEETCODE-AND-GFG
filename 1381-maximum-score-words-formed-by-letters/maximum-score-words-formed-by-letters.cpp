class Solution {
    int solve(int i,vector<string>& words,unordered_map<char,int>mp,vector<int>& score)
    {
        if(i==words.size())return 0;
        int ans=0,temp=0;
        ans=solve(i+1,words,mp,score);
        for(auto it:words[i]){
            if(mp[it]>0){
                mp[it]--;
                temp+=score[it-'a'];
            }else{
                return ans;
            }
        }
        return max(ans,temp+solve(i+1,words,mp,score));
    }
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char,int>mp;
        for(auto it:letters){
            mp[it]++;
        }
        return solve(0,words,mp,score);

    }
};