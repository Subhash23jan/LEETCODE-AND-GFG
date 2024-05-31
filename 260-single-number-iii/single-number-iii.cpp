class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int XOR=0;
        for(auto it:nums){
            XOR^=it;
        }
        int i=0;
        while((XOR>>i & 1)==0){
            i++;
        }
        int A=0,B=0;
        for(auto it:nums){
            if((it>>i & 1)==0){
                A^=it;
            }else{
                B^=it;
            }
        }
        return {A,B};
    }
};