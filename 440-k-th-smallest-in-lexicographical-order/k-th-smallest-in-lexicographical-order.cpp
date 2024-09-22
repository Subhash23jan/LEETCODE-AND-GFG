class Solution
{
    int calculate(long long n1, long long n)
    {
        long long n2 = n1 + 1;
        int cnt = 0;
        while (n1 <= n)
        {
            cnt += (min(n2, n + 1) - n1);
            n1 *= 10;
            n2 *= 10;
        }
        return cnt;
    }

    public:
        int findKthNumber(int n, int k, long long num = 1)
        {
            if (k == 1)
            {
                return num;
            }
            int noOfPossibleValues = calculate(num, n);
            if (noOfPossibleValues < k)
            {
                return findKthNumber(n, k - noOfPossibleValues, num + 1);
            }
            return findKthNumber(n, k - 1, num *10);
        }
};