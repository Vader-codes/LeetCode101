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
    TreeNode* helper(vector<int>&preorder, int &i, int bound){
        // base case for recursion
        if(i == preorder.size() || preorder[i] > bound)return NULL;
        
        int val = preorder[i++];
        TreeNode* root = new TreeNode(val);

        root->left = helper(preorder, i, val);
        root->right = helper(preorder,i, bound );
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int i =0;
        return helper(preorder, i, INT_MAX);
    }
};