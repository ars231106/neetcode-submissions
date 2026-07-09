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

    int search(vector<int>& inorder, int value, int left, int right){
        for(int i = 0; i<inorder.size(); i++){
            if(inorder[i] == value){
                return i;
            }
        }
        return -1;
    }

    TreeNode * helper(vector<int>& preorder, vector<int>& inorder, int &preidx, int left, int right){
        if(left > right){
            return NULL;
        }

        int value = preorder[preidx];
        TreeNode* root = new TreeNode(value);
        preidx++;

        int idridx = search(inorder, value, left, right);
        root -> left = helper(preorder, inorder, preidx, left, idridx - 1);
        root -> right = helper(preorder, inorder, preidx, idridx + 1, right);

        return root;

        
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preidx = 0;
        TreeNode* root = helper(preorder, inorder, preidx, 0, inorder.size() - 1);
        return root;
    }
};
