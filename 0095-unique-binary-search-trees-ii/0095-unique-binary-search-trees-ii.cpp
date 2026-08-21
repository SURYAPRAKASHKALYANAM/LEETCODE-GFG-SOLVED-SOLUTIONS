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
    TreeNode* cloneTree(TreeNode* root) {
        if (root == nullptr)
            return nullptr;

        TreeNode* newNode = new TreeNode(root->val);

        newNode->left = cloneTree(root->left);
        newNode->right = cloneTree(root->right);

        return newNode;
    }
    vector<TreeNode*> find(int start, int end) {
        vector<TreeNode*> ans;
        if (start > end)
            return ans;
        if (start == end)
            return {new TreeNode(start)};
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> left = find(start, i - 1);
            vector<TreeNode*> right = find(i + 1, end);
            TreeNode* curr = new TreeNode(i);
            if (left.size() && right.size()) {
                for (auto l : left) {
                    curr->left = l;
                    for (auto r : right) {
                        curr->right = r;
                        ans.emplace_back(cloneTree(curr));
                    }
                    curr->left = curr->right = nullptr;
                }
            } else if (left.size()) {
                for (auto l : left) {
                    curr->left = l;
                    ans.emplace_back(cloneTree(curr));
                }
                curr->left = nullptr;
            } else {

                for (auto r : right) {
                    curr->right = r;
                    ans.emplace_back(cloneTree(curr));
                }
                curr->right = nullptr;
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) { return find(1, n); }
};