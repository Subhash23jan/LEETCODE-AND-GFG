class Solution {
public:
    static int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        const int n=customers.size();
        auto it=customers.begin();
        
        // Compute the satisfaction using secret technique in first minutes
        int satisfied=accumulate(it, it+minutes, 0);
        
        
        // Add satisfaction from non-grumpy periods outside the initial window
        for (int i = minutes; i < n; i++) 
            satisfied+= (1-grumpy[i])*customers[i];
        
        // This is the initial maximum satisfaction with the initial window
        int max_satisfied= satisfied;
        
        // Sliding window for applying non-grumpy technique
        for (int i = minutes; i < n; i++) {
            // Remove the effect of the left-most element 
            satisfied -= (grumpy[i-minutes])*customers[i-minutes];
            // Add the effect of the current element
            satisfied += grumpy[i]*customers[i];
            // Update the maximum satisfaction
            max_satisfied = max(max_satisfied, satisfied);
        }
        
        return max_satisfied;
    }
};




auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();