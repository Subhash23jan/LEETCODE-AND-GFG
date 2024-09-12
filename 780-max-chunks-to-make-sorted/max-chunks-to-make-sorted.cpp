class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int num=0;
        int ans=0;
        for(int i=0;i<arr.size();i++)
        {
            num=(num|(1<<(arr[i])));
            if(num==(1<<(i+1))-1){
                ans++;
            }
        }
        return ans;
    }
};