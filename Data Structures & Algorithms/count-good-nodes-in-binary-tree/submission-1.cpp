/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int ans = 0;

    bool isGood(TreeNode* root, TreeNode* target, int maxi) {
        if (root == NULL)
            return false;

        maxi = max(maxi, root->val);

        if (root == target) {
            return target->val >= maxi;
        }

        return isGood(root->left, target, maxi) ||
               isGood(root->right, target, maxi);
    }

    void traverse(TreeNode* originalRoot, TreeNode* curr) {
        if (curr == NULL)
            return;

        if (isGood(originalRoot, curr, INT_MIN))
            ans++;

        traverse(originalRoot, curr->left);
        traverse(originalRoot, curr->right);
    }

    int goodNodes(TreeNode* root) {
        traverse(root, root);
        return ans;
    }
};