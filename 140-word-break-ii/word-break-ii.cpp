class Trie
{
    public:
        Trie *children[26];
    bool isEnd;
    Trie()
    {
        for (int i = 0; i < 26; i++)
        {
            this->children[i] = nullptr;
            this->isEnd = false;
        }
    }
};
class Solution
{
    void solve(int index, string s, vector<string> &ans, string str)
    {
        if (index == s.size())
        {
            ans.push_back(str);
            return;
        }
        string tmp = "";
        for (int i = index; i < s.size(); i++)
        {
            tmp += s[i];
            if (searchWord(tmp))
            {
                if (index == 0)
                    solve(i + 1, s, ans, str + tmp);
                else
                {
                    solve(i + 1, s, ans, str + " " + tmp);
                }
            }
        }
    }
    void addWord(string str)
    {
        Trie *temp = root;
        for (int i = 0; i < str.size(); i++)
        {
            char ch = str[i];
            if (!temp->children[ch - 'a'])
            {
                temp->children[ch - 'a'] = new Trie();
            }
            temp = temp->children[ch - 'a'];
        }
        temp->isEnd = true;
    }
    bool searchWord(string str)
    {
        Trie *temp = root;
        for (int i = 0; i < str.size(); i++)
        {
            char ch = str[i];
            if (!temp->children[ch - 'a'])
            {
                return false;
            }
            temp = temp->children[ch - 'a'];
        }
        return temp->isEnd;
    }
    public:
        Trie *root = new Trie();
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        for (auto it: wordDict)
        {
            addWord(it);
        }
        vector<string> ans;
        solve(0, s, ans, "");
        return ans;
    }
};