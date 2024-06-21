/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void getValues(vector<int>&arr,TreeNode* root)
    {
        if(!root)return;
        getValues(arr,root->left);
        arr.push_back(root->val);
        getValues(arr,root->right);
    }
    TreeNode *buildTree(vector<int>arr,int l,int r)
    {
        if(l>r) return nullptr;
        int mid=l+(r-l)/2;
        TreeNode *root=new TreeNode(arr[mid]);
        root->left=buildTree(arr,l,mid-1);
        root->right=buildTree(arr,mid+1,r);
        return root;

    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>arr;
        getValues(arr,root);
        return buildTree(arr,0,arr.size()-1);
    }
};