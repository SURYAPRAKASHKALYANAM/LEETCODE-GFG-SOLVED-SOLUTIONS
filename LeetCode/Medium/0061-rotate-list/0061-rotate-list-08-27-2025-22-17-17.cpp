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
/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
*/

class Solution {
public:
    int lenght(ListNode* node) {
        int cnt = 0;
        while (node) {
            cnt++;
            node = node->next;
        }
        return cnt;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next)
            return head;
        ListNode* temp = head;
        int len = lenght(head);
        k = k % len;
        while (k) {
            temp = temp->next;
            // if (!temp)
            //     temp = head;
            k--;
        }
        if (temp == head)
            return head;
        ListNode *newH, *start = head;
        while (temp->next) {
            start = start->next;
            temp = temp->next;
        }
        newH = start->next;
        start->next = nullptr;
        temp->next = head;
        return newH;
    }
};