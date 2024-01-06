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
class Solution
{
    public:
        vector<int> presuc(vector<int> &ino, int v)
        {
            vector<int> ans = {-1,-1};
            int low = 0, high = ino.size() - 1;
            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                if (ino[mid] == v) return {v,v};
                if (ino[mid] < v)
                {
                    ans[0] = ino[mid];
                    low = mid + 1;
                }
                else
                {
                    ans[1] = ino[mid];
                    high = mid - 1;
                }
            }
            return ans;
        }
    vector<vector < int>> closestNodes(TreeNode *root, vector<int> &queries)
    {
        vector<vector < int>> ans;
        vector<int> ino;
        TreeNode *temp = root;
        while (temp)
        {
            if (temp->left == NULL)
            {
                ino.emplace_back(temp->val);
                temp = temp->right;
            }
            else
            {
                TreeNode *prev = temp->left;
                while (prev->right && prev->right != temp) prev = prev->right;
                if (prev->right == NULL)
                {
                    prev->right = temp;
                    temp = temp->left;
                }
                else
                {
                    prev->right = NULL;
                    ino.emplace_back(temp->val);
                    temp = temp->right;
                }
            }
        }
        for (auto i: queries)
        {
            ans.emplace_back(presuc(ino, i));
        }
        return ans;
    }
};