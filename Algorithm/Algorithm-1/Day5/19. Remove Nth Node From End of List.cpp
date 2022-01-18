class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        
        ListNode *slow = dummy, *fast = dummy;
        
        for(int i = 0; i < n+1; ++i){
            fast = fast->next;
        }
        //slow and fast are n+1 apart
        
        while(fast){
            slow = slow->next;
            fast = fast->next;
        }
        //slow is n+1 from tail->next, so n from tail
        //so it's (n+1)-last node
        
        ListNode* tmp = slow->next;
        slow->next = slow->next->next;
        delete tmp;
        
        return dummy->next;
    }
};