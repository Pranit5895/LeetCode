/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
enum class State{
    BP, //BOTH_PENDING
    LD, //LEFT_DONE
    BD //BOTH_DONE
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<pair<TreeNode*, State>> stk;
        
        stk.push(make_pair(root, State::BP));
        bool foundOne = false; //either found p or q
        TreeNode* LCA = nullptr;
        TreeNode *cur = nullptr, *child = nullptr;
        State curState;
        
        while(!stk.empty()){
            pair<TreeNode*, State> top = stk.top();
            cur = top.first;
            curState = top.second;
            
            if(curState != State::BD){
                if(curState == State::BP){
                    if(cur == p || cur == q){
                        if(foundOne){
                            //we have found the second
                            return LCA;
                        }else{
                            foundOne = true;
                            LCA = cur;
                        }
                    }

                    child = cur->left;
                }else{
                    child = cur->right;
                }
            
                //revise cur's state
                stk.pop();
                stk.push(make_pair(cur, (State)((int)curState+1)));

                if(child){
                    stk.push(make_pair(child, State::BP));
                }
            }else{
                TreeNode* tmp = stk.top().first;
                stk.pop();
                if(LCA == tmp && foundOne){
                    LCA = stk.top().first;
                }
            }
        }
        
        return nullptr;
    }
};
