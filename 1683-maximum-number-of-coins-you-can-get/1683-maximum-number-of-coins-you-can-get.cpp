class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int i=0,j=piles.size()-1;
        sort(piles.begin(),piles.end());
        int ans=0;
        while(i<j)
        {
            j--;
            ans+=piles[j--];
            i++;
        }
        return ans;
    }
};