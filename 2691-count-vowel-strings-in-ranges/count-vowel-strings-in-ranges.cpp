class SegmentTree
{
    vector<int> arr;
    int n;
    bool isVowel(char ch)
    {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    int query(int ind, int low, int high, int l, int r)
    {
        if (high < l || low > r) return 0;
        if (low >= l && high <= r) return arr[ind];
        int mid = (low + high) / 2;
        return query(2 *ind + 1, low, mid, l, r) + query(2 *ind + 2, mid + 1, high, l, r);
    }
    void build(int i, int l, int r, const vector<string> &words)
    {
        if (l == r)
        {
            arr[i] = (isVowel(words[l][0]) && isVowel(words[l].back()));
            return;
        }
        int mid = (l + r) / 2;
        build(2 *i + 1, l, mid, words);
        build(2 *i + 2, mid + 1, r, words);
        arr[i] = arr[2 *i + 1] + arr[2 *i + 2];
        return;
    }
    public:
        SegmentTree(const vector<string> &words)
        {
            n = words.size();
            arr.resize(4 *n, 0);
            build(0, 0, n - 1, words);
        }
    int query(int l, int r)
    {
        return query(0, 0, n - 1, l, r);
    }
};
class Solution
{
    public:
        vector<int> vowelStrings(vector<string> &words, vector<vector< int>> &queries)
        {
            vector<int> ans;
            SegmentTree seg(words);
            for (auto it: queries)
            {
                ans.push_back(seg.query(it[0], it[1]));
            }
            return ans;
        }
};