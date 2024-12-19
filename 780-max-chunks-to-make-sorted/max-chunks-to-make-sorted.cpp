class Solution
{
    int solve(int i, vector<int> arr, int sum)
    {
        int n = arr.size();
        if (i == n)
        {
            return 0;
        }
        int temp = (i *(i + 1)) / 2;
        sum += arr[i];
        if (sum == temp)
        {
            return 1 + solve(i + 1, arr, sum);
        }
        return solve(i + 1, arr, sum);
    }
    public:
        int maxChunksToSorted(vector<int> &arr)
        {
            int n = arr.size();
            return solve(0, arr, 0);
        }
};