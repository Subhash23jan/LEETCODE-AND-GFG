class Solution {
public:
    bool judgeSquareSum(int c) {
        long long i=0,j=sqrt(c);
        while(i<=j)
        {
            auto sum=(i*i)+(j*j);
            if(sum==c) return true;
            if(sum<c) i++;
            else j--;
        }
        return false;
    }
};