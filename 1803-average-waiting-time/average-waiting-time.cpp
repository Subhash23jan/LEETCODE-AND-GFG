class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int currTime=customers[0][0];
        double waitingTime=0;
        for(auto it:customers)
        {
            if(it[0]>currTime)
            {
                currTime=it[0];
            }
            currTime+=it[1];
            waitingTime+=(currTime-it[0]);
        }
        return waitingTime/customers.size();
    }
};