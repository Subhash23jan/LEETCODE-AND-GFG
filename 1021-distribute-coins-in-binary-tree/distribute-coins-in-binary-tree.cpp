class Solution {
    int solve(TreeNode* root,int &moves){
        if(!root) return 0;
        int lft=solve(root->left,moves);
        int rgt=solve(root->right,moves);
        moves+=abs(lft)+abs(rgt);
        return  root->val-1+lft+rgt;
    }
public:
    int distributeCoins(TreeNode* root) {
        int moves=0;
        solve(root,moves);
        return moves;
    }
};