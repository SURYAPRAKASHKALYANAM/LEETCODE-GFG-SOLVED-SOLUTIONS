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
    ListNode* helper(ListNode* prev, ListNode* curr, ListNode* end) {
        if (curr == end)
            return prev;
        ListNode* start = curr->next;
        curr->next = prev;
        return helper(curr, start, end);
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int cnt = k;
        ListNode *resultHead = NULL;
        ListNode *end = head, *prevEnd = NULL;
        while (end) {
            ListNode* start = end;
            while (end && cnt) {
                end = end->next;
                cnt--;
            }
            if (cnt == 0) {
                ListNode* newHead = helper(NULL, start, end);
                if (!resultHead) {
                    resultHead = newHead;
                }
                if (prevEnd) {
                    prevEnd->next = newHead;
                }
                prevEnd = start;
            } else {
                if (prevEnd)
                    prevEnd->next = start;
                else
                    resultHead = head;
            }
            cnt = k;
        }
        return resultHead;
    }
};