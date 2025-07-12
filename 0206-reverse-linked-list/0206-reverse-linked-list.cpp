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
    ListNode* helper(ListNode* prev, ListNode* curr) {
        if (!curr)
            return prev;
        ListNode* temp = curr->next;
        curr->next = prev;
        return helper(curr, temp);
    }
    ListNode* reverseList(ListNode* head) {
        return helper(NULL, head);
        // if (!head)
        //     return NULL;
        // ListNode* prevNode = NULL;
        // ListNode *curr = head, *currNext = NULL;
        // while (curr) {
        //     currNext = curr->next;
        //     curr->next = prevNode;
        //     prevNode = curr;
        //     curr = currNext;
        // }
        // return prevNode;
    }
};