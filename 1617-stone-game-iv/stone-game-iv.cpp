class Solution {
    vector<int>vec;
    int solve(int n)
    {
        if(n==0)return false;
        if(vec[n]!=-1) return vec[n];
        for(int i=sqrt(n);i>=1;i--)
        {
            if(!solve(n-i*i)) return vec[n]=true;
        }
        return vec[n]=false;
    }
public:
    bool winnerSquareGame(int n) {
        vec.resize(n+1,-1);
        return solve(n);
    }
};