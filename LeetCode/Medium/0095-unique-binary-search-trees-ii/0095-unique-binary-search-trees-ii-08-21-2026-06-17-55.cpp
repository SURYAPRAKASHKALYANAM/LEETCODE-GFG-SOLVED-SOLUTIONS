class Solution {
public:
    vector<TreeNode*> find(int start, int end) {
        vector<TreeNode*> ans;
        if (start > end) {
            ans.push_back(nullptr);   
            return ans;
        }
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> lefts  = find(start, i - 1);
            vector<TreeNode*> rights = find(i + 1, end);
            for (auto l : lefts) {
                for (auto r : rights) {
                    ans.push_back(new TreeNode(i, l, r));
                }
            }
        }
        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return find(1, n);
    }
};