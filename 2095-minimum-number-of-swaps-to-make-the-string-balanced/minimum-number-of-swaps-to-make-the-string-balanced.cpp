class Solution {
public:
    int minSwaps(string s) {
        int cnt=0,ans=0;
        for(auto ch:s)
        {
            if(ch=='['){
                cnt++;
            }else{
                if(cnt){
                    cnt--;
                }else{
                    ans++;
                }
            }
        }
        return (ans+1)/2;
    }
};