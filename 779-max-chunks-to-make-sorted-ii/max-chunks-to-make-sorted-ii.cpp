class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size(),ans=0;
        priority_queue<int>pq1,pq2;
        vector<int>nums=arr;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            pq1.push(nums[i]);
            pq2.push(arr[i]);
            while(pq1.size() && pq1.top()==pq2.top()){
                pq1.pop();
                pq2.pop();
            }
            if(pq1.size()==0 && pq2.size()==0) ans++;
        }
        return ans;
    }
};