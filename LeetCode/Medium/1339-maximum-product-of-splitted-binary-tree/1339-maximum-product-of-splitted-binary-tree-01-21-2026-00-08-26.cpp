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
    int mod = 1e9 + 7;
    long long totalSum = 0;
    long long maxProd = 0;
    void addAll(TreeNode* root) {
        if (!root)
            return;
        totalSum += (root->val);
        addAll(root->left);
        addAll(root->right);
    }
    long long helper(TreeNode* root) {
        if (!root)
            return 0;
        long long left = helper(root->left);
        long long right = helper(root->right);
        maxProd = max(maxProd, left * (totalSum - left));
        maxProd = max(maxProd, right * (totalSum - right));
        return root->val + left + right;
    }
    int maxProduct(TreeNode* root) {
        addAll(root);
        helper(root);
        return maxProd % mod;
    }
};