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
    int bestpath = 0; 
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int leftside = height(root -> left);
        int rightside = height(root -> right);

        bestpath = max(bestpath, leftside + rightside);
        return 1 + max(leftside, rightside);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return bestpath;
    }   
};
