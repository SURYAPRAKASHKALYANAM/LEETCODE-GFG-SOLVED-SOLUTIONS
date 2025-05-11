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
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root)
            return {};
        stack<TreeNode*> st;
        vector<int> inorder;
        st.push(root);
        while (!st.empty()) {
            auto root = st.top();
            if (root->left) {
                st.push(root->left);
                root->left = NULL;
                continue;
            }
            inorder.emplace_back(root->val);
            st.pop();
            if (root->right)
                st.push(root->right);
        }
        return inorder;
    }
};