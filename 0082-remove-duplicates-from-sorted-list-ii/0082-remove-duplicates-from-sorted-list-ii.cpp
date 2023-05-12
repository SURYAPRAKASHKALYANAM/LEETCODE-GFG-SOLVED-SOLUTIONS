/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* deleteDuplicates(ListNode *head)
        {
            ListNode *ans = NULL, *tail = NULL, *temp = head;
            map<int, int> m;
            while (temp)
            {
                if (temp->next == NULL)
                {
                    if (m[temp->val] == 0)
                    {
                        if (tail)
                        {
                            tail->next = temp;
                            tail = temp;
                            tail->next = NULL;
                        }
                        else
                        {
                            ans = temp;
                            tail = temp;
                        }
                    }
                }
                else if (m[temp->val] == 0 && temp->val != temp->next->val)
                {
                    if (ans == NULL)
                    {
                        ans = temp;
                        tail = temp;
                    }
                    else
                    {
                        tail->next = temp;
                        tail = temp;
                    }
                }
                m[temp->val]++;
                temp = temp->next;
                if(tail) tail->next=NULL;
            }
            return ans;
        }
};