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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<pair<TreeNode* , TreeNode*>>q;
        q.push({root, nullptr});

        while(!q.empty()){
            int n  = q.size();
            TreeNode* parentx = nullptr;
            TreeNode* parenty = nullptr;

            for(int i=0; i<n; i++){
                auto[node, parent] = q.front(); q.pop();

                if(node->val == x){
                    parentx = parent;
                }
                if(node->val == y){
                    parenty = parent;
                }

                if(node->left)q.push({node->left, node});
                if(node->right)q.push({node->right, node});
            }

            // cases
            if(parentx && parenty){
                // found both need to check the parent
                return parentx != parenty;
            }
            if(parentx || parenty){
                // only fonund one at some level definetely not neighbours
                return false;
            }

        }
        return false;
    }
};