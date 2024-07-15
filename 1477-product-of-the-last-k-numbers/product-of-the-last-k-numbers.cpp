class ProductOfNumbers
{
    int cnt = 0;
    unordered_map<int, int> mp;
    vector<int> vec;
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
            vec.push_back(cnt);
        }
        if (cnt == 1)
        {
            mp[cnt] = num;
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
        int ele = cnt - k;
        int index = upper_bound(vec.begin(), vec.end(), ele) - vec.begin();
        if (index < vec.size())
        {
            return 0;
        }
        if (mp[ele] == 0)
        {
            return mp[cnt];
        }
        return mp[cnt] / mp[ele];
    }
};

/**
 *Your ProductOfNumbers object will be instantiated and called as such:
 *ProductOfNumbers* obj = new ProductOfNumbers();
 *obj->add(num);
 *int param_2 = obj->getProduct(k);
 */