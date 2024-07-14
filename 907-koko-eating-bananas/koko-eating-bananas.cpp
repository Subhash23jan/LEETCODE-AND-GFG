class Solution
{
    public:
        int minEatingSpeed(vector<int> &piles, int h)
        {
            int r = *max_element(piles.begin(), piles.end())*2, l = 1;
            int ans = 1;
            while (l < r)
            {
                int mid = (l + r) / 2;
                int sum = 0, cnt = 0;
                for (auto it: piles)
                {
                    cnt += (it / mid);
                    if (it % mid != 0) cnt++;
                }
                cout << cnt << " " << mid << endl;
                if (cnt > h)
                {
                    l = mid+1;
                }
                else
                {
                    ans = mid;
                    r = mid;
                }
            }
            return ans;
        }
};