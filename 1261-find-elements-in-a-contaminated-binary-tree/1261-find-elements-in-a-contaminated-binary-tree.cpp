/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class FindElements
{
    public:
        unordered_map<int, int> m;
    void build(TreeNode *root)
    {
        if (root == NULL) return;
        if (root->left)
        {
            root->left->val = root->val *2 + 1;
            m[(root->val *2 + 1)]++;
        }
        if (root->right)
        {
            root->right->val = root->val *2 + 2;
            m[root->val *2 + 2]++;
        }
        build(root->left);
        build(root->right);
    }
    FindElements(TreeNode *root)
    {
        root->val = 0;
        m[0]++;
        build(root);
    }
    bool find(int target) {
        return m[target];
    }
};

/**
 *Your FindElements object will be instantiated and called as such:
 *FindElements* obj = new FindElements(root);
 *bool param_1 = obj->find(target);
 */