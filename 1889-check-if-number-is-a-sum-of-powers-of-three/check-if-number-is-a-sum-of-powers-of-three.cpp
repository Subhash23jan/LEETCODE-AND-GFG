class Solution
{
    bool solve(int i, int n)
    {
        long long temp = pow(3, i);
        if (temp > n) return false;
        if (temp == n) return true;
        return solve(i + 1, n) || solve(i + 1, n - temp);
    }
    public:
        bool checkPowersOfThree(int n)
        {
            return solve(0, n);
        }
};