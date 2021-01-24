class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt=0;
        ListNode*temp=head;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        if(n==cnt){
            head=head->next;
            return head;
        }
        int acnt=cnt-n-1;
        ListNode*x=head;
        while(acnt){
            acnt--;
            x=x->next;
        }
        
        x->next=x->next->next;
        return head;
        
    }
};