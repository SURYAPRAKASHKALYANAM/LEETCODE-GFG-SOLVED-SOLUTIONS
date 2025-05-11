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
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> preorder;
        stack<TreeNode*> st;
        while (1) {
            if(root){
                st.push(root);
                preorder.push_back(root->val);
                root=root->left;
            }
            else{
                if(st.empty()) break;
                root= st.top();st.pop();
                root=root->right;
            }
        }
        return preorder;
    }
};