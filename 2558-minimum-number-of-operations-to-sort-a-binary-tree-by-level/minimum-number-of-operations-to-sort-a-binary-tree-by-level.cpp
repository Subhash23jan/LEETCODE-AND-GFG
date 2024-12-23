/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *int val;
 *TreeNode * left;
 *TreeNode * right;
 *TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    int minSwaps(vector<int> arr)
    {
        int n = arr.size();
        vector<pair<int, int>> vec;
        for (int i = 0; i < n; i++)
        {
            vec.push_back({ arr[i],i });
        }
        sort(vec.begin(), vec.end());
        vector<bool> vis(n, false);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (vis[i] || vec[i].second == i) continue;
            int size = 0, j = i;
            while (!vis[j])
            {
                vis[j] = true;
                j = vec[j].second;
                size++;
            }
            ans += (size - 1);
        }
        return ans;
    }

    public:
        int minimumOperations(TreeNode *root)
        {
            queue<TreeNode*> q;
            if (root)
            {
                q.push(root);
            }
            int ans = 0;
            while (q.size())
            {
                int n = q.size();
                vector<int> arr;
                while (n--)
                {

                    auto node = q.front();
                    q.pop();
                    arr.push_back(node->val);
                    if (node->left)
                    {
                        q.push(node->left);
                    }
                    if (node->right)
                    {
                        q.push(node->right);
                    }
                }
                ans += minSwaps(arr);
            }
            return ans;
        }
};