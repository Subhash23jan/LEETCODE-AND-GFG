class ProductOfNumbers
{
    int cnt = 0;
    stack<int> st;
    unordered_map < long long, int> mp;
    public:
        ProductOfNumbers()
        {
            mp[0] = 1;
        }

    void add(int num)
    {
        cnt++;
        if (num == 0)
        {
            st.push(cnt);
        }
        else
        {
            if (mp[cnt - 1] == 0)
            {
                mp[cnt] = num;
            }
            else
            {
                mp[cnt] = mp[cnt - 1] *num;
            }
        }
    }

    int getProduct(int k)
    {
        auto size = -k;
        if (st.size())
        {
            size = st.top();
        }
        if ((cnt - size) < k) return 0;
        if (mp[cnt - k] == 0) return mp[cnt];
        return mp[cnt] / mp[cnt - k];
    }
};

/**
 *Your ProductOfNumbers object will be instantiated and called as such:
 *ProductOfNumbers* obj = new ProductOfNumbers();
 *obj->add(num);
 *int param_2 = obj->getProduct(k);
 */