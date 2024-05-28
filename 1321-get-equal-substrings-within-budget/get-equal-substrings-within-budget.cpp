class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.size();
        int arr[n];
        for(int i=0;i<n;i++)
        {
            arr[i]=abs(t[i]-s[i]);
        }
        int ans=0;
        long long sum=0;
        int i=0,j=0;
        while(j<n){
            sum+=arr[j++];
            while(i<n && sum>maxCost){
                sum-=arr[i];
                i++;
            }
            ans=max(ans,j-i);
        }
        return ans;
    }
};