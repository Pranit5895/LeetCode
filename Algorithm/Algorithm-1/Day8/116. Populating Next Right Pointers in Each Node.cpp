class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        
        Node *prev = root, *cur = nullptr;
        
        //while prev is not a leaf
        while(prev->left){
            //in each iteration, connect all nodes in prev's next level
            cur = prev;
            while(cur){
                cur->left->next = cur->right;
                if(cur->next) cur->right->next = cur->next->left;
                //move rightward, in the same level
                cur = cur->next;
            }
            //go to next level
            prev = prev->left;
        }
        
        return root;
    }
};