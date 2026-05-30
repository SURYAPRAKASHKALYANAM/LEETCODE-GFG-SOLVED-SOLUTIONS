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
    ListNode* partition(ListNode* head, int x) {
        ListNode *smaller = nullptr, *larger = nullptr;
        ListNode *temp = head, *sb = nullptr, *lb = nullptr;
        while (temp) {
            if (temp->val < x) {
                if (!sb)
                    sb = smaller = temp;
                else {
                    smaller->next = temp;
                    smaller = temp;
                }
            } else {
                if (!lb)
                    lb = larger = temp;
                else {
                    larger->next = temp;
                    larger = temp;
                }
            }
            temp = temp->next;
        }
        if (larger)
            larger->next = nullptr;
        if (smaller)
            smaller->next = lb;
        return sb ? sb : lb;
    }
};