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
    vector<int> ans;
    
    void preorder(TreeNode* node, int depth){
        if(!node) return;
        
        /*
        only push value to the vector 
        when we meet first element in that depth
        
        note that right child is visited before left child,
        so the first element in that depth will be
        the rightmost node in that depth
        */
        if(depth == ans.size()){
            ans.push_back(node->val);
        }
        
        preorder(node->right, depth+1);
        preorder(node->left, depth+1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        preorder(root, 0);
        
        return ans;
    }
};
