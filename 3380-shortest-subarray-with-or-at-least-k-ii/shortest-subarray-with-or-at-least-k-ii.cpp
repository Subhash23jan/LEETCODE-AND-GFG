
class Solution
{
    public:
        int minimumSubarrayLength(vector<int> &nums, int k)
        {
            vector<int> bits(32, 0);	
            int num = 0, i = 0, j = 0, n = nums.size();
            int ans = INT_MAX;

            for (i = 0; i < n; i++)
            {
                for (int b = 0; b < 32; b++)
                {
                    if (nums[i] >> b &1)
                    {
                        bits[b]++;
                        if (bits[b] == 1)
                        {
                            num += (1 << b);
                        }
                    }
                }

                while (num >= k && i>=j)
                {
                    ans = min(ans, i - j + 1);

                    for (int b = 0; b < 32; b++)
                    {
                        if (nums[j] >> b & 1)
                        {
                            bits[b]--;
                            if (bits[b] == 0)
                            {
                                num -= (1 << b);
                            }
                        }
                    }
                    j++;
                }
            }
            return (ans == INT_MAX) ? -1 : ans;
        }
};