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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0)
            return head;

        int len = 1;
        ListNode* tail = head;
        while (tail->next) {
            len++;
            tail = tail->next;
        }

        k = k % len;
        if (k == 0)
            return head;

        tail->next = head;

        // Find the new tail, which is located at (len - k - 1) steps from
        //  head The new head will be the node right after the new tail
        ListNode* newTail = head;
        for (int i = 0; i < len - k - 1; i++) {
            newTail = newTail->next;
        }

        // Break the ring and establish the new head
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
        // if (!head || !head->next)
        //     return head;
        // ListNode* temp = head;
        // int len = lenght(head);
        // k = k % len;
        // while (k) {
        //     temp = temp->next;
        //     k--;
        // }
        // if (temp == head)
        //     return head;
        // ListNode *newH, *start = head;
        // while (temp->next) {
        //     start = start->next;
        //     temp = temp->next;
        // }
        // newH = start->next;
        // start->next = nullptr;
        // temp->next = head;
        // return newH;
    }
    // int lenght(ListNode* node) {
    //     int cnt = 0;
    //     while (node) {
    //         cnt++;
    //         node = node->next;
    //     }
    //     return cnt;
    // }
};