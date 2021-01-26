class Solution
{
public:
    ListNode *reverse(ListNode *head)
    {
        ListNode *curr = head, *prev = NULL, *nxt;
        while (curr != NULL)
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    bool isPalindrome(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return true;
        ListNode *fast = head, *slow = head;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        slow->next = reverse(slow->next);
        slow = slow->next;
        // cout<<slow->val;
        while (slow != NULL)
        {
            if (head->val != slow->val)
                return false;
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
};