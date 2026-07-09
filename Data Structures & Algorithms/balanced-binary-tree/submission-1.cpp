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
public:
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int leftside = height(root -> left);
        int rightside = height(root -> right);

        return 1 + max(leftside, rightside); 
    }

    bool isBalanced(TreeNode* root) {
       if(root == NULL){
          return true;
       }

       int leftside = height(root -> left);
       int rightside = height(root -> right);

       if(abs(leftside - rightside) > 1){
           return false;
       }

       return isBalanced(root -> left) && isBalanced(root -> right);
    }
};
