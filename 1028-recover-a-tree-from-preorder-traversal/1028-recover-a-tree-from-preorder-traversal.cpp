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
    string traverse;
    int pos, len, next_height = 0;
    int findval() {
        int num = 0;
        while (traverse[pos] <= '9' && traverse[pos] >= '0' && pos < len) {
            num = num * 10 + (traverse[pos++] - '0');
        }
        return num;
    }
    int findheight() {
        int height = 0;
        while (traverse[pos] == '-' && pos < len) {
            height++;
            pos++;
        }
        return height;
    }
    TreeNode* helper(TreeNode* root, int prev_height) {
        if (next_height != prev_height + 1 ||
            (prev_height != -1 && !next_height)) {
            return nullptr;
        }
        int num = findval();
        if (num) {
            root->val = num;
            next_height = findheight();
            root->left = helper(new TreeNode(), prev_height + 1);
            root->right = helper(new TreeNode(), prev_height + 1);
            return root;
        }
        return nullptr;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        traverse = traversal;
        pos = 0, len = traversal.size();
        TreeNode* root = new TreeNode();
        return helper(root, -1);
    }
};