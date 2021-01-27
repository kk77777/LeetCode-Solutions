class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL || head->next == NULL || k == 0)
            return head;
        ListNode *temp = head;
        int cnt = 1;
        while (temp->next != NULL)
        {
            temp = temp->next;
            cnt++;
        }
        temp->next = head;
        k = k % cnt;
        k = cnt - k;
        while (k--)
        {
            temp = temp->next;
        }
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};