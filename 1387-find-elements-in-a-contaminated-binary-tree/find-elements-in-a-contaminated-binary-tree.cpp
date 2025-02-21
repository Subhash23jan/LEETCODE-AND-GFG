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
class FindElements
{
    TreeNode *treeRoot = NULL;
    bool solve(TreeNode *root, int val, int target)
    {
        if (!root || val > target) return false;
        if (val == target) return true;
        return solve(root->left, 2 *val + 1, target) || solve(root->right, 2 *val + 2, target);
    }
    public:
        FindElements(TreeNode *root)
        {
            if (root) root->val = 0;
            treeRoot = root;
        }

    bool find(int target)
    {
        return solve(treeRoot, 0, target);
    }
};

/**
 *Your FindElements object will be instantiated and called as such:
 *FindElements* obj = new FindElements(root);
 *bool param_1 = obj->find(target);
 */