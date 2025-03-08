class Solution
{
    public:
        int minimumRecolors(string blocks, int k)
        {
            int cnt = 0, ans = k + 1;
            for (int i = 0; i < k; i++)
            {
                if (blocks[i] == 'B')
                {
                    cnt++;
                }
            }
            ans = min(ans, k - cnt);
            for (int i = k; i < blocks.size(); i++)
            {
                if (blocks[i - k] == 'B')
                {
                    cnt--;
                }
                if (blocks[i] == 'B')
                {
                    cnt++;
                }
                ans = min(ans, k - cnt);
            }
            return ans;
        }
};