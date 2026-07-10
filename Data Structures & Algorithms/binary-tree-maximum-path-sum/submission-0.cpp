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

    int maxsum = INT_MIN;

    int maxPathSum(TreeNode* root){
        dfs(root);
        return maxsum;
    }

    int dfs(TreeNode* root) {

        if(root == NULL) {
            return 0;
        }

        int leftside = dfs(root -> left);
        int rightside = dfs(root -> right);

        //check for negetive subtree 
        leftside = max(0, leftside);
        rightside = max(0, rightside);

        int currsum = leftside + root -> val + rightside;

        maxsum = max(currsum, maxsum);

        return root -> val + max(leftside, rightside);
    }
};
