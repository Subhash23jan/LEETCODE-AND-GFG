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
    int solve(TreeNode *root, int &k)
    {
        if (!root) return -1;
        int ans = solve(root->left, k);
        k--;
        if (k == 0) return root->val;
        int temp=solve(root->right, k);
        
        return max(temp,ans);
    }
    public:
        int kthSmallest(TreeNode *root, int k)
        {
            return solve(root, k);
        }
};