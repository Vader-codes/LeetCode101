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
    unordered_map<int,int>mp;
    int maxD =0;

    void findDepth(TreeNode* root, int d){
        if(!root)return;

        mp[root->val] = d;
        maxD = max(maxD, d);
        findDepth(root->left, d+1);
        findDepth(root->right, d+1);
    }
    TreeNode* lca(TreeNode* root){
        // base case
        if(!root || mp[root->val] == maxD)return root;


        TreeNode* l = lca(root->left);
        TreeNode* r = lca(root->right);

        if(l && r)return root;

        return !l? r : l;
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
         findDepth(root, 0);

        return lca(root);
    }
};