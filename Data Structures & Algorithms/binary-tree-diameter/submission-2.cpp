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
private:
    int getHeight(TreeNode* root, int& res) {
        if (!root) return 0;
        
        int left = getHeight(root->left, res);
        int right = getHeight(root->right, res);
        
        // Update the global maximum diameter with the path passing through this node
        res = max(res, left + right);
        
        // Return the height of this subtree to its parent
        return 1 + max(left, right);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        getHeight(root, res);
        return res;
    }
};