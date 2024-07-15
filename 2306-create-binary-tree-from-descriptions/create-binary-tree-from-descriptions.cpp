/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_map<int, int> parentMap;
        for (auto it : descriptions) {
            int parent = it[0];
            int child = it[1];
            parentMap[child] = parent;
            TreeNode* parentNode = nullptr;
            TreeNode* childNode = nullptr;
            if(mp.count(child)){
                childNode=mp[child];
            }else{
                childNode=new TreeNode(child);
                mp[child]=childNode;
            }
            if (mp.count(parent)) {
                parentNode = mp[parent];
            } else {
                parentNode = new TreeNode(parent);
                mp[parent] = parentNode;
            }
            if (it[2] == 1) {
                parentNode->left = childNode;
            } else {
                parentNode->right = childNode;
            }
        }
        for (auto it : descriptions) {
            int parent = it[0];
            if (!parentMap.count(parent)) {
                return mp[parent];
            }
        }
        return nullptr;
    }
};