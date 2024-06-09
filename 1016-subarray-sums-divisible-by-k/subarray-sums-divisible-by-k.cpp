class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int>mp;
        long long sum=0;
        int ans=0;
        mp[0]++;
        for(auto it:nums){
            sum+=it;
            int rem=sum%k;
            if(rem<0){
                rem+=k;
            }
            cout<<rem<<endl;
            if(mp.count(rem)){
                ans+=mp[rem];
            }
            mp[rem]++;
        }
        return ans;
    }
};