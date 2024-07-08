class Solution
{
    public:
        int findTheWinner(int n, int k)
        {
            vector<int> vis(n, 0);
            int cnt = 0;
            int dlted = 0;
            while (dlted < n - 1)
            {
                int temp = k - 1;
                while (temp--)
                {
                    while (vis[cnt])
                    {
                        cnt++;
                        cnt = cnt % n;
                    }
                    cnt++;
                    cnt = cnt % n;
                }
                while (vis[cnt])
                {
                    cnt++;
                    cnt = cnt % n;
                }
                vis[cnt]=1;
                dlted++;
                cnt++;
                cnt = cnt % n;
            }
            for(int i=0;i<n;i++)
            {
                if(vis[i]==0) return i+1;
            }
            return n;
        }
};