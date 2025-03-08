class Solution {
public:
    bool isPrime(int n)
    {
            if(n==1)
                    return false;
            if(n<=3)
                    return true;
            for(int i=2;i*i<=n;i++)
            {
                    if(n%i==0)
                            return false;
            }
            return true;
    }
    vector<int> closestPrimes(int left, int right) {
        
            vector<int>ans(2,-1);
            int minimum=1000000;
            int prev;
            for(int i=left;i<=right;i++)
            {
                    if(isPrime(i))
                    {
                            prev=i;
                            break;
                    }
            }
            for(int i=prev+1;i<=right;i++)
            {
                    if(isPrime(i))
                    {
                            if(minimum>(i-prev))
                            {
                                    ans[0]=prev;
                                    ans[1]=i;
                                    minimum=i-prev;
                            }
                            prev=i;
                    }
            }
            return ans;
            
    }
};