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
        int max, min, sum,maxsum;
    NodeValue(int max, int min, int sum,int maxsum)
    {
        this->max = max;
        this->min = min;
        this->sum = sum;
        this->maxsum=maxsum;
    }
};
class Solution
{
    public:
        NodeValue maxsum(TreeNode *root)
        {
            if (!root) return NodeValue(INT_MIN, INT_MAX, 0,0);
            auto left = maxsum(root->left);
            auto right = maxsum(root->right);
            int rmax=max(left.maxsum,right.maxsum);
            if (root->val > left.max && root->val < right.min)
            {
                return NodeValue(max(right.max, root->val), min(left.min, root->val),root->val + left.sum + right.sum,max(rmax,root->val + left.sum + right.sum));
            }
            return NodeValue(INT_MAX, INT_MIN, max(left.sum, right.sum),rmax);
        }
    int maxSumBST(TreeNode *root)
    {
        return max(0, maxsum(root).maxsum);
    }
};