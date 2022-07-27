/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* cur = root;
        
        while(cur){
            if(cur->left){
                TreeNode* prev = cur->left;
                
                while(prev->right) prev = prev->right;
                //now prev is cur's predecessor in in-order traversal
                //it's also rightmost node of cur's left subtree
                
                //let cur's right subtree be cur's left subtree's descendants
                //prev->right must be nullptr, so this op is safe
                prev->right = cur->right;
                //move cur's left subtree to the right
                cur->right = cur->left;
                //the reconstructed tree don't have left children
                cur->left = nullptr;
            }
            
            //move forward in the reconstructed tree
            cur = cur->right;
        }
    }
};
