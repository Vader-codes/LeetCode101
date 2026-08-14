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
    bool dfs(TreeNode* root, vector<TreeNode*>&arr, TreeNode* target){
     // base case
      if(!root)return false;

      arr.push_back(root);

      if(root == target)return true;

      if(dfs(root->left, arr, target) || dfs(root->right, arr, target))return true;

      arr.pop_back();
      return false;

    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || !p || !q)return NULL;

        vector<TreeNode*>root_to_p;
        vector<TreeNode*>root_to_q;
        
        dfs(root, root_to_p,p);
        dfs(root, root_to_q,q);
        

        int i=0;
        TreeNode* lca = NULL;
        while( i < root_to_p.size() && i < root_to_q.size()){

            if(root_to_p[i] == root_to_q[i])lca = root_to_p[i];

            else break;
            i++;
    
        }
        return lca;
    }
};