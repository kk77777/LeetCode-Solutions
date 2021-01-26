class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int>s;
        ListNode*fast=head,*slow=head;
        while(fast!=NULL && fast->next!=NULL){
            s.push(slow->val);
            fast=fast->next->next;
            slow=slow->next;
        }
        if(fast!=NULL) slow=slow->next;
        while(slow!=NULL){
            if(s.top()!=slow->val){
                return false;
            }
            s.pop();
            slow=slow->next;
        }
        return true;
    }
};