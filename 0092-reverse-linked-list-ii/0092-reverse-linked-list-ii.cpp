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
    pair<ListNode*, ListNode*> helper(ListNode* prev, ListNode* curr, int pos,
                                      int right) {
        if (pos == right + 1)
            return {prev, curr};
        ListNode* temp = curr->next;
        curr->next = prev;
        return helper(curr, temp, pos + 1, right);
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *temp = head, *prev = NULL;
        int pos = 1;
        while (1) {
            if (pos == left - 1)
                prev = temp;
            if (pos == left) {
                auto it = helper(temp, temp->next, pos + 1, right);
                ListNode* newHead = it.first;
                if (prev) {
                    prev->next = newHead;
                } else
                    head = newHead;
                temp->next = it.second;
                break;
            }
            pos++;
            temp = temp->next;
        }
        return head;
    }
};