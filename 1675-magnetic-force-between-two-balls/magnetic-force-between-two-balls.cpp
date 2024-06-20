class Solution
{
    public:
        int maxDistance(vector<int> &position, int m)
        {
            sort(position.begin(), position.end());
            int l = 0, r = INT_MAX;
            int ans = 0, n = position.size();
            while(l<r)
            {
                int mid=(l+r)/2;
                int prev=position[0];
                int cnt=1;
                for(int i=1;i<n;i++)
                {
                    if(position[i]-prev>=mid){
                        cnt++;
                        prev=position[i];
                    }
                }
                cout<<cnt<<" "<<mid<<endl;
                if(cnt>=m){
                    l=mid+1;
                    ans=mid;
                }else{
                    r=mid;
                }
            }
            return ans;
        }
};