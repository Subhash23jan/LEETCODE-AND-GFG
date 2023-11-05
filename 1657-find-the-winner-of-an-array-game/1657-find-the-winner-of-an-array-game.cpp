class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int maxVal=arr[0];
        int cnt=0;
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]<maxVal)
            {
                cnt++;
            }else{
                maxVal=arr[i];
                cnt=1;
            }
            if(cnt==k)
            return maxVal;
        }
        return maxVal;
    }
};