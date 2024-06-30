class Solution
{
    public:
        int maximumLength(vector<int> &nums)
        {
            vector<int> arr = nums;
            int n = nums.size();
            for (int i = 0; i < n; i++)
            {
                arr[i] %= 2;
            }
            int ans = 0;
            int cnt = 0;
            int flag = 0;
            for (int i = 0; i < n; i++)
            {
                if (flag == arr[i])
                {
                    cnt++;
                    flag = 1 - flag;
                }
            }
            ans = max(ans, cnt);
            cnt = 0;
            flag = 1;
            for (int i = 0; i < n; i++)
            {
                if (flag == arr[i])
                {
                    cnt++;
                    flag = 1 - flag;
                }
            }
            ans = max(ans, cnt);
            cnt = 0;
            flag = 1;
            for (int i = 0; i < n; i++)
            {
                if (flag == arr[i])
                {
                    cnt++;
                }
            }
            ans = max(ans, cnt);
            cnt = 0;
            flag = 0;
            for (int i = 0; i < n; i++)
            {
                if (flag == arr[i])
                {
                    cnt++;
                }
            }
            ans = max(ans, cnt);
            cnt = 0;
            return ans;
        }
};