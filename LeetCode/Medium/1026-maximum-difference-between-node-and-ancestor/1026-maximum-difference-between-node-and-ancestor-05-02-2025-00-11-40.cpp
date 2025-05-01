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
    int max_dis = 0;

public:
    void minmax(TreeNode* root, int max_a, int min_a) {
        if (!root)
            return;
        if (!root->left && !root->right) {
            max_dis =
                max(max_dis, max(max_a, root->val) - min(min_a, root->val));
        }
        minmax(root->left, max(max_a, root->val), min(min_a, root->val));
        minmax(root->right, max(max_a, root->val), min(min_a, root->val));
    }
    int maxAncestorDiff(TreeNode* root) {
        minmax(root, root->val, root->val);
        return max_dis;
    }
};