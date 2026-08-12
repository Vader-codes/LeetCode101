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
    private:
     TreeNode* helper(TreeNode* root, int sum, int limit){
        if(!root)return NULL;
        // add curr value to sum
        sum+=root->val;

        // leaf : check the complet root to leaf path
        if(!root->left && !root->right){
            if(sum < limit)return NULL;

            return root;
        }
        root->left = helper(root->left, sum , limit);
        root->right = helper(root->right, sum, limit);
        // what if from this root there is no sufficient path
        if(!root->left && !root->right)return NULL;

        return root;
     }
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        return helper(root, 0, limit);
    }
};