class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int>dp;
        for(auto it:bills)
        {
            if(it==5){
                dp[it]++;
            }else{
               int change=it-5;
               while(change>=10 && dp[10]>0){
                 change-=10;
                 dp[10]--;
               }
               while(change>0 && dp[5]>0){
                 change-=5;
                 dp[5]--;
               }
               if(change>0){
                 return false;
               }
               dp[it]++;
            }
        }
        return true;
    }
};