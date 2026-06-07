/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *  int val;
 *  TreeNode * left;
 *  TreeNode * right;
 *  TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        TreeNode* createBinaryTree(vector<vector < int>> &descriptions)
        {
            unordered_map<int, TreeNode*> address, parent;
            for (auto desc: descriptions)
            {
                if (!address[desc[0]]) address[desc[0]] = new TreeNode(desc[0]);
                if (desc[2])
                {
                    if (!address[desc[1]]) address[desc[1]] = new TreeNode(desc[1]);
                    address[desc[0]]->left = address[desc[1]];
                }
                else
                {
                    if (!address[desc[1]]) address[desc[1]] = new TreeNode(desc[1]);
                    address[desc[0]]->right = address[desc[1]];
                }
                parent[desc[1]] = address[desc[0]];
            }
            for (auto i: address)
            {
                if (parent[i.first] == NULL) return address[i.first];
            }
            return NULL;
        }
};