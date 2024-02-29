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
class Solution
{
    public:
        bool isEvenOddTree(TreeNode *root)
        {
            queue<TreeNode*> q;
            q.push(root);
            bool flag = 1;
            int comp = 0;
            while (!q.empty())
            {
                int n = q.size();
                if (flag) comp = 0;
                else comp = INT_MAX;
                for (int i = 0; i < n; i++)
                {
                    auto it = q.front();
                    int v = it->val;
                    q.pop();
                    if (flag)
                    {
                        if (v & 1)
                        {
                            if (v > comp) comp = v;
                            else return false;
                        }
                        else return false;
                    }
                    else
                    {
                        if (!(v & 1))
                        {
                            if (v < comp) comp = v;
                            else return false;
                        }
                        else return false;
                    }

                    if (it->left) q.push(it->left);
                    if (it->right) q.push(it->right);
                }
                flag = !flag;
            }
            return true;
        }
};