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
    unordered_map<int, int>inorderIdx;
    int postIdx;
    TreeNode* helper(vector<int>& postorder, int left, int right){
        // base case
        if(left > right)return NULL;

        int val = postorder[postIdx--];

        TreeNode* root = new TreeNode(val);
        int mid = inorderIdx[val];

        root->right = helper(postorder, mid+1, right);
        root->left = helper(postorder, left, mid-1);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0; i<inorder.size(); i++){
            inorderIdx[inorder[i]] = i;
        }
        postIdx = postorder.size()-1;
        return helper(postorder,0, inorder.size()-1);
    }
};