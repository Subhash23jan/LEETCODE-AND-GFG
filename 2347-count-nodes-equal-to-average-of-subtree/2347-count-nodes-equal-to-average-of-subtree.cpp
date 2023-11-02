/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        int cnt = 0;
    map<int, int> mp;
    pair<int, int> solve(TreeNode *root)
    {
        if (!root)
            return { 0,
                0 };
        pair<int, int> p1 = solve(root->left);
        pair<int, int> p2 = solve(root->right);
        int average = (p1.first + p2.first + root->val) / (p1.second + p2.second + 1);
        cnt += (average==root->val);
        return {
            p1.first + p2.first + root->val,
            p1.second + p2.second + 1
        };
    }

    int averageOfSubtree(TreeNode *root)
    {
        solve(root);
        return cnt;
    }
};