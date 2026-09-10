/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class NodeValue
{
    public:
        int sum, n, cnt;
    NodeValue(int sum, int n, int cnt)
    {
        this->sum = sum;
        this->n = n;
        this->cnt = cnt;
    }
};
class Solution
{
    public:
        NodeValue helper(TreeNode *root)
        {
            if (!root) return NodeValue(0, 0, 0);
            auto left = helper(root->left);
            auto right = helper(root->right);
            int avg = (root->val + left.sum + right.sum) / (1 + left.n + right.n);
            if (avg == root->val) return NodeValue(root->val + left.sum + right.sum, 1 + left.n + right.n, 1 + left.cnt + right.cnt);
            return NodeValue(root->val + left.sum + right.sum, 1 + left.n + right.n, left.cnt + right.cnt);
        }
    int averageOfSubtree(TreeNode *root)
    {
        return helper(root).cnt;
    }
};