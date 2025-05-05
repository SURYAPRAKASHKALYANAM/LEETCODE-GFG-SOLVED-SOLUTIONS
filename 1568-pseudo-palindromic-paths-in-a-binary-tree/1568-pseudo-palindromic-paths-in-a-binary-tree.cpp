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
    void helper(TreeNode* root, vector<int> counts, int& cnt) {
        if (!root) {
            return;
        }
        if (!root->left && !root->right) {
            counts[root->val]++;
            cnt += (count_if(counts.begin(), counts.end(),
                             [](int n) { return n & 1; }) <= 1);
        } else {
            counts[root->val]++;
            helper(root->left, counts, cnt);
            helper(root->right, counts, cnt);
        }
    }
    int pseudoPalindromicPaths(TreeNode* root) {
        vector<int> counts(10, 0);
        int cnt = 0;
        helper(root, counts, cnt);
        return cnt;
    }
};