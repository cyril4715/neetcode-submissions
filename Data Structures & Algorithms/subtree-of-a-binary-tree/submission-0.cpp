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
    bool sametree(TreeNode* s ,TreeNode* t){
         if (!s && !t) {
            return true;
        }
        if ((s && t) && (s->val == t->val)){
         return (sametree(s->left , t->left) && 
                 sametree(s->right, t->right));
        }
        return false;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot) return true; // root exist but subroot null .root null child = subroot
        if(!root) return false; //root null but subroot exist

        if (sametree(root, subRoot)){ 
             return true;
        }

        return (isSubtree(root->left, subRoot) ||  // check left root subtree against subroot
               isSubtree(root->right, subRoot));
        
    }

};
