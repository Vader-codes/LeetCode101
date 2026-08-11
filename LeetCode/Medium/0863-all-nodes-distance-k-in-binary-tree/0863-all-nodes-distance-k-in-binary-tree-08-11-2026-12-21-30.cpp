/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void findParent(unordered_map<TreeNode*, TreeNode*>&parent, TreeNode* root){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                TreeNode* node = q.front(); q.pop();
                if(node->left){
                    parent[node->left]= node;
                    q.push(node->left);
                }
                if(node->right){
                    parent[node->right] = node;
                    q.push(node->right);
                }
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*>parent;
        findParent(parent, root);
        unordered_map<TreeNode* , bool>visited;
        visited[target] = true;
        queue<TreeNode*>q;
        q.push(target);

        int level =0;
        while(!q.empty()){
            int size = q.size();
            
            if(level == k)break;

            while(size--){
                TreeNode* node = q.front();
                q.pop();

                if(node->left && !visited[node->left]){
                    visited[node->left] = true;
                    q.push(node->left);
                }
                if(node->right && !visited[node->right]){
                    visited[node->right] = true;
                    q.push(node->right);
                }
                if( parent[node] && !visited[parent[node]]){
                    q.push(parent[node]);
                    visited[parent[node]]= true;
                }

            }
            level++;


        }
         // now the q contains all the nodes at k levels from target
            vector<int>ans;
            while(!q.empty()){
                ans.push_back(q.front()->val);
                q.pop();
            }
            return ans;
    }
};