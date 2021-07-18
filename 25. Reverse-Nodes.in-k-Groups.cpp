//Runtime: 20 ms, faster than 39.60% of C++ online submissions for Reverse Nodes in k-Group.
//Memory Usage: 10.3 MB, less than 16.67% of C++ online submissions for Reverse Nodes in k-Group.
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
    void reverseTwoNodes(ListNode** a, ListNode** b){
        //a and b are pointer of pointer
        //a->x->... and b->y->... to b->a->x->... and y->...
        // cout << "reverse: " << (*a)->val << " and " << (*b)->val << endl;
        ListNode* latter = (*b)->next;
        (*b)->next = *a;
        //a->(b) and b->y->... to b->a->y->...
        if((*a)->next == *b) (*a)->next = nullptr;
        *a = *b;
        *b = latter;
        // cout << "reversed: " << ((*a) ? (*a)->val : -1) << " and " << ((*b) ? (*b)->val : -1) << endl;
    };
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        //check if the length of list >= k
        ListNode* tail = head;
        //go forward for k-1 steps
        for(int i = 0; i < k-1 && tail; ++i){
            tail = tail->next;
        }
        //the list's length < k, don't need to reverse it
        if(!tail) return head;
        
        //reverse the first k node and call function for rest nodes
        ListNode* laterHead = reverseKGroup(tail->next, k);
        
        // cout << "head: " << head->val << ", tail: " << tail->val << endl;
        ListNode *cur = head, *next = head->next;
        //each time reverse two nodes, reverse for k-1 times
        for(int i = 0; i < k-1; ++i){
            reverseTwoNodes(&cur, &next);
        }
        
        // cout << "new head: " << tail->val << ", new tail: " << head->val << endl;
        // cout << "the reversed group: ";
        // cur = tail;
        // while(cur){
        //     cout << cur->val << " ";
        //     cur = cur->next;
        // }
        // cout << endl;
        
        //original head of group now becomes the new tail
        head->next = laterHead;
        //tail is now the head of reversed list
        return tail;
    }
};

//recursion
//https://leetcode.com/problems/reverse-nodes-in-k-group/discuss/11423/Short-but-recursive-Java-code-with-comments
//Runtime: 24 ms, faster than 26.27% of C++ online submissions for Reverse Nodes in k-Group.
//Memory Usage: 10.1 MB, less than 77.96% of C++ online submissions for Reverse Nodes in k-Group.
//space: O(n/k) used by recursion stack
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = head;
        
        int steps = 0;
        
        for(; steps < k && cur; ++steps){
            cur = cur->next;
        }
        
        //list's length < k, don't need to reverse
        if(steps < k) return head;
        
        //now cur is the head of next group, reverse that group first
        cur = reverseKGroup(cur, k);
        
        /*
        123456, k = 3
        assume the later group is already reversed: 123654
        head: 1, cur: 6
        "head" is the head of list to be reversed, 
        and it should be connected to the head of reversed list,
        so we set head->next to "cur"
        tmp: 2, head->next: 6,
        and later do the following:
        cur: 1, head: 2
        so that cur is still the head of reversed list and
        "head" is still the head of the list to be reversed
        
        we do this for k times,
        tmp: 3, head->next: 1, cur: 2, head: 3
        tmp: nullptr, head->next: 2, cur: 3, head: nullptr
        
        to summary, in each iteration,
        we cut the head of forward list and append it to the head of reversed list,
        and this process is done for k times,
        meaning cutting for k times and appending for k times
        */
        for(int i = 0; i < k; ++i){
            //"head": head of the list to be reversed
            ListNode* tmp = head->next;
            //cur: head of reversed list
            head->next = cur;
            cur = head;
            head = tmp;
        }
        
        return cur;
    }
};