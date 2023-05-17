/**
 *Definition for singly-linked list.
 *struct ListNode {
 *int val;
 *ListNode * next;
 *ListNode() : val(0), next(nullptr) {}
 *ListNode(int x) : val(x), next(nullptr) {}
 *ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *int val;
 *TreeNode * left;
 *TreeNode * right;
 *TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        bool find(ListNode *head, TreeNode *root)
        {
            if (!root)
            {
                if (!head) return true;
                else return false;
            }
            if (!head) return true;
            if (root->val == head->val) return find(head->next, root->left) || find(head->next, root->right);
            else return false;
        }
    bool isSubPath(ListNode *head, TreeNode *root)
    {
        if (!root) return false;
        bool lh = isSubPath(head, root->left);
        if (lh) return true;
        lh = isSubPath(head, root->right);
        if (lh) return lh;
        if (root->val == head->val) return find(head, root);
        return lh;
    }
};