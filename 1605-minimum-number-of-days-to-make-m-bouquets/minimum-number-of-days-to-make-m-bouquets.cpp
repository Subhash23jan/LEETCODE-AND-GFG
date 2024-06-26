class Solution
{
    public:
        int n;

    bool f(int d, vector<int> &bloomDay, int m, int k)
    {
        int len = 0, bouquet = 0;
        for (int i = 0; i < n; i++)
        {
            if (bloomDay[i] <= d)
            {
                len++;	// length for the adjacent blooming flowers
                if (len == k)
                {
                    bouquet++;	
                    len = 0;	
                }
            }
            else len = 0;	

            if (bouquet >= m) return 1;	
        }
        return bouquet >= m;
    }

    int minDays(vector<int> &bloomDay, int m, int k)
    {
        n = bloomDay.size();
        if ((long long) m * k > n) return -1;

        auto[x0, xN] = minmax_element(bloomDay.begin(), bloomDay.end());
        int l = *x0, r = *xN, mid;

        while (l < r)
        {
            mid = l + (r - l) / 2;
            if (f(mid, bloomDay, m, k))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};