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
    ListNode *node;
    Solution(ListNode* head) {
        node = head;
    }
    
    int getRandom() {
        int val;
        ListNode *tmp = node;
        int len = 0;
        while(tmp!=NULL){
            len++;
            tmp=tmp->next;
        }

        // cout<<len<<endl;

        int random = 0 + (rand()%len);
        // cout<<random<<endl;

        tmp = node;
        int cnt = 0;
        tmp=node;

        while(cnt!=random){
           cnt++;
           tmp=tmp->next;
        }

        return tmp->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */