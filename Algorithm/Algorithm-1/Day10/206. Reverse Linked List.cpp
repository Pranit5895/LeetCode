class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* p = reverseList(head->next);
        //head->next: tail of p
        //the new tail of p becomes head
        head->next->next = head;
        head->next = NULL;
        return p;
    }
};