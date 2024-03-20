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
        ListNode* mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
        {
            ListNode *ath, *bth, *temp = list1;
            int loc = 0;
            while (temp)
            {
                loc++;
                if (loc == a) ath = temp;
                if (loc - 1 == b)
                {
                    bth = temp;
                    break;
                }
                temp = temp->next;
            }
            ath->next = list2;
            temp = list2;
            while (temp->next) temp = temp->next;
            temp->next = bth->next;
            return list1;
        }
};