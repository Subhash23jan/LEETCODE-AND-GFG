class Solution
{
    bool solve(vector<int> &derived, int num)
    {
        int n = derived.size();
        vector<int> original(n);
        original[0] = num;
        for (int i = 0; i < n; i++)
        {
            original[(i + 1) % n] = derived[i] ^ original[i];
        }
        return original[0] == num;
    }
    public:
        bool doesValidArrayExist(vector<int> &derived)
        {
            int n = derived.size();
            return solve(derived, 1) || solve(derived, 0);
        }
};