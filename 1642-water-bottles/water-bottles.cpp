class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=numBottles;
        while(numBottles>=numExchange)
        {
            int bottles=numBottles/numExchange;
            ans+=(bottles);
            int temp=numBottles%numExchange;
            numBottles=bottles+temp;
        }
        return ans;
    }
};