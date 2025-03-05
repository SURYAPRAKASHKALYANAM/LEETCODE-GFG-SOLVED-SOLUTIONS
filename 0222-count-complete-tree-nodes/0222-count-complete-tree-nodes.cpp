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
    int leftHeight(TreeNode* root) {
        if (!root)
            return 0;
        return 1 + leftHeight(root->left);
    }
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        int left_d = leftHeight(root->left);
        int right_d = leftHeight(root->right);
        if (left_d == right_d) {
            return pow(2, left_d) + countNodes(root->right);
        } else {
            return pow(2, right_d) + countNodes(root->left);
        }
    }
};