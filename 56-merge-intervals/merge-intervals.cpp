class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        auto temp=intervals[0];
        for(auto it:intervals)
        {
            if(temp[1]<it[0]){
                ans.push_back(temp);
                temp=it;
            }else{
                temp[1]=max(it[1],temp[1]);
            }
        }
        ans.push_back(temp);
        return ans;
    }
};