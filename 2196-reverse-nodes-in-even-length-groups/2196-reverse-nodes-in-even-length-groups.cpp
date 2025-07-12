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
    ListNode* helper(ListNode* prev, ListNode* start, ListNode* end) {
        if (start == end)
            return prev;
        ListNode* nextPtr = start->next;
        start->next = prev;
        return helper(start, nextPtr, end);
    }
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        int grpCnt = 1;
        ListNode *prevEnd = NULL, *end = head, *beforeEnd = head;
        while (end) {
            ListNode* start = end;
            int cnt = 0;
            while (end && cnt < grpCnt) {
                end = end->next;
                cnt++;
                if (cnt == grpCnt - 1) {
                    beforeEnd = end;
                }
            }
            if (cnt & 1) {
                if (prevEnd)
                    prevEnd->next = start;
                prevEnd = beforeEnd;
            } else {
                ListNode* newHead = helper(NULL, start, end);
                if (prevEnd) {
                    prevEnd->next = newHead;
                }
                prevEnd = start;
            }
            ++grpCnt;
        }
        return head;
    }
};