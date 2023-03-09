class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if(head==NULL) return head;
        ListNode *fast = head, *slow = head;

        while(fast!=NULL and fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow) {break;}
        }

        if(fast==NULL or fast->next==NULL) return NULL;

        ListNode * ptr1 = head, *ptr2 = slow;

        while(ptr1!=ptr2){
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }

        return ptr1;
    }
};