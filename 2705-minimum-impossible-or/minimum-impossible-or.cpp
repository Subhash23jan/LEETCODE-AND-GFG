class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        set<int>st(nums.begin(),nums.end());
        int i=0;
        for(auto it:st)
        {
            if(it==(1<<i))
            {
                i++;
            }else if(it>(1<<i)){
                return 1<<i;
            }
        }
        return 1<<i;
    }
};