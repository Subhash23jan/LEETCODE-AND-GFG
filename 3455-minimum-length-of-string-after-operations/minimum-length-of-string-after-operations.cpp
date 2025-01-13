class Solution {
public:
    int minimumLength(string s) {
        map<char,int>mp;
        int sum=0;
        for(auto it:s)
        {
            mp[it]++;
        }
        for(auto &it:mp)
        {
            int cnt=it.second;
            while(cnt>=3){
                int tmp=cnt/3;
                int rem=(cnt%3);
                cnt=3*tmp;
                cnt-=(2*tmp);
                cnt+=rem;   
            }
            sum+=cnt;
        }
        return sum;
        
        
    }
};