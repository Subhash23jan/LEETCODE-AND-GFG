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
    map<pair<TreeNode*,int>,int>mp;
    int solve(TreeNode *root, bool prev)
    {
        if (!root) return 0;
        if(mp.count({root,prev})){
            return mp[{root,prev}];
        }
        if (prev)
        {
            return mp[{root,prev}]=solve(root->left, false) + solve(root->right, false);
        }
        else
        {
            int lft = solve(root->left, true) + solve(root->right, true) + root->val;
            int rght = solve(root->left, false) + solve(root->right, false);
            return mp[{root,prev}]= max(lft, rght);
        }
    
    }
    public:
        int rob(TreeNode *root)
        {
            int sum = 0;
            bool prev = false;
            return max(solve(root, true), solve(root, false));
        }
};