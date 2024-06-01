class Solution {
public:
    vector<int> countSmaller(vector<int>& arr) {
        int n=arr.size();
        vector<int>ans(n,0);
        stack<int>st;
        vector<int>temp;
        for(int i=n-1;i>=0;i--)
        {
            int index=lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin();
            ans[i]=index;
            temp.insert(lower_bound(temp.begin(),temp.end(),arr[i]),arr[i]);
        }
        return ans;
    }
};