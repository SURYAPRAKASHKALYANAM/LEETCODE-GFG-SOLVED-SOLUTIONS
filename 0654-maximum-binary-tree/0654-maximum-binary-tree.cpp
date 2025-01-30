/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *  int val;
 *  TreeNode * left;
 *  TreeNode * right;
 *  TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 *right(right) {}
 *};
 */
class Solution
{
    public:
        int max_find(vector<int> &nums, int beg, int end)
        {
            return max_element(nums.begin() + beg, nums.begin() + end + 1) - nums.begin();
        }
    TreeNode* dfs(int start, int end, vector<int> &visited, vector<int> &nums)
    {
        if (start < 0 || start >= visited.size() || end < 0 ||
            end >= visited.size())
            return nullptr;
        if (visited[start] || visited[end])
            return nullptr;
        int max_pos = max_find(nums, start, end);
        visited[max_pos] = 1;
        return new TreeNode(nums[max_pos],
            dfs(start, max_pos - 1, visited, nums),
            dfs(max_pos + 1, end, visited, nums));
    }
    TreeNode* constructMaximumBinaryTree(vector<int> &nums)
    {
        vector<int> visited(nums.size(), 0);
        return dfs(0, nums.size() - 1, visited, nums);
    }
};