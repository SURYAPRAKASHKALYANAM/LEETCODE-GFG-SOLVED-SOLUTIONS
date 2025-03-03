/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Anna Namaste
        ListNode *root = nullptr, *prev = nullptr;
        int temp = k;
        stack<ListNode*> st;
        while (head) {
            ListNode* prevorig = head;
            while (temp > 0 && head) {
                st.push(head);
                head = head->next;
                temp--;
            }
            if (temp == 0) {
                while (!st.empty()) {
                    if (!root) {
                        prev = root = st.top();
                    } else {
                        prev->next = st.top();
                        prev = st.top();
                    }
                    st.pop();
                }
                if (!head)
                    prev->next = NULL;
            } else {
                if (!root)
                    prev = root = prevorig;
                else
                    prev->next = prevorig;
                if (!head)
                    st.top()->next = NULL;
            }
            temp = k;
        }
        return root;
    }
};