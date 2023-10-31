class Solution {
public:
    vector<int> findArray(vector<int>& ans) {
       int n=ans.size();
       for(int i=n-1;i>0;i--)
       {
               ans[i]=(ans[i]^ans[i-1]);
       }
            return ans;
    }
};