/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL or head->next==NULL) return head;
        
        ListNode * ptr = head;
        
        // fun(ptr,ptr->next,false,head);
        
        while(ptr!=NULL and ptr->next!=NULL){
            // ListNode * nextNode = ptr->next;
            
            ListNode* ptr2=ptr->next;
            while(ptr2 and ptr2->val==ptr->val) ptr2=ptr2->next;
            ptr->next=ptr2;
            ptr=ptr->next;
        }
        
        
        return head;
    }
};