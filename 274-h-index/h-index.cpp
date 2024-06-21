class Solution {
public:
    int hIndex(vector<int>& citations) {
        int l=0,n=citations.size(),r=*max_element(citations.begin(),citations.end());
        int ans=0;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            int cnt=0;
            for(auto it:citations)
            {
                if(it>=mid){
                    cnt++;
                }
            }
            if(cnt>=mid)
            {
                ans=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return ans;
    }
};