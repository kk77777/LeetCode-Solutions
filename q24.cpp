class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *nextHead = head->next->next;
        ListNode *newHead = head->next;
        head->next->next = head;
        head->next = swapPairs(nextHead);
        return newHead;
    }
};