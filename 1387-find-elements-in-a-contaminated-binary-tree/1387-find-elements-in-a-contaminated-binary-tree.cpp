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
class FindElements {
public:
    unordered_map<int, int> have;
    void fill(TreeNode* root, int val) {
        if (root == NULL)
            return;
        have[val] = 1;
        root->val = val;
        fill(root->left, 2 * val + 1);
        fill(root->right, 2 * val + 2);
    }
    FindElements(TreeNode* root) { fill(root, 0); }

    bool find(int target) { return have[target]; }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */