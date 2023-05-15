/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {
        map<ListNode*,int> m;
        while(head)
        {
            if(m[head]) return head;                //if head is found again => cycle detected
            m[head]++;                              // keep track of head in map 
            head=head->next;
        }
        return head;
    }
};