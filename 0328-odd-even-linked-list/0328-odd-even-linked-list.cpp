/**
 *Definition for singly-linked list.
 *struct ListNode {
 *  int val;
 *  ListNode * next;
 *  ListNode() : val(0), next(nullptr) {}
 *  ListNode(int x) : val(x), next(nullptr) {}
 *  ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* oddEvenList(ListNode *head)
        {
            if (!head) return NULL;
            ListNode *temp = head, *odd = NULL, *even = NULL, *oddend, *evenend, *next;
            int i = 1;
            while (temp)
            {
                next = temp->next;
                if (i % 2)
                {
                    if (!odd)
                    {
                        odd = temp;
                        odd->next = NULL;
                        oddend = temp;
                    }
                    else
                    {
                        oddend->next = temp;
                        oddend = temp;
                        temp->next = NULL;
                    }
                }
                else
                {
                    if (!even)
                    {
                        even = temp;
                        temp->next = NULL;
                        evenend = temp;
                    }
                    else
                    {
                        evenend->next = temp;
                        temp->next = NULL;
                        evenend = temp;
                    }
                }
                i++;
                temp = next;
            }
            oddend->next = even;
            return odd;
        }
};