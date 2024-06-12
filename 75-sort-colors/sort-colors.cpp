class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        int k=0;
        while(k<=j)
        {
            int val=nums[k];
            if(val==0){
                swap(nums[i],nums[k]);
                if(k==i)k++;
                i++;
            }else if(val==2){
                swap(nums[j],nums[k]);
                j--;
            }else{
                k++;
            }
        }
        return ;
    }
};