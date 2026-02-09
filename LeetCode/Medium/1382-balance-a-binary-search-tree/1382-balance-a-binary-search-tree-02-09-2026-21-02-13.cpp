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
    void inorder(TreeNode* root, vector<int>& arr) {
        if (!root)
            return;
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        inorder(root, arr);
        return build(0, arr.size() - 1, arr);
    }
    TreeNode* build(int start, int end, vector<int>& arr) {
        if (end < start)
            return nullptr;
        int mid = start + ((end - start) / 2);
        return new TreeNode(arr[mid], build(start, mid - 1, arr),
                            build(mid + 1, end, arr));
    }
};