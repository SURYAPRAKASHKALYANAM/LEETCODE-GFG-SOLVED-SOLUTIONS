/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* add(vector<vector < int>> &ans, int rs, int re, int cs, int ce, ListNode *head)
        {
            for (int i = cs; i <= ce; i++)
            {
                if (head)
                {
                    ans[rs][i] = head->val;
                    head = head->next;
                }
                else ans[rs][i] = -1;
            }
            for (int i = rs + 1; i <= re; i++)
            {
                if (head)
                {
                    ans[i][ce] = head->val;
                    head = head->next;
                }
                else ans[i][ce] = -1;
            }
            for (int i = ce - 1; i > cs && rs != re; i--)
            {
                if (head)
                {
                    ans[re][i] = head->val;
                    head = head->next;
                }
                else ans[re][i] = -1;
            }
            for (int i = re; i > rs && ce != cs; i--)
            {
                if (head)
                {
                    ans[i][cs] = head->val;
                    head = head->next;
                }
                else ans[i][cs] = -1;
            }
            return head;
        }
    vector<vector < int>> spiralMatrix(int m, int n, ListNode *head)
    {
        vector<int> v(n, 0);
        vector<vector < int>> ans(m, v);
        int row_start = 0, row_end = m - 1, col_start = 0, col_end = n - 1;
        ListNode * temp;
        while (row_start <= row_end && col_start <= col_end)
        {
            head = add(ans, row_start, row_end, col_start, col_end, head);
            row_start++;
            row_end--;
            col_start++;
            col_end--;
        }
        return ans;
    }
};