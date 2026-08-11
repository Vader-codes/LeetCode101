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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        stack<TreeNode*>st;
        // this is for storing the nodes in decreasing order
        for(int x : nums){
            // create the node of this element
            TreeNode* cur = new TreeNode(x);
            // any smaller element on the top of the stack belongs to the left subtree
            // of curr
            while(!st.empty() && st.top()->val < x){
                cur->left = st.top();
                st.pop();
            }
            if(!st.empty()){
                st.top()->right = cur;
            }
            st.push(cur);
        }
        while(st.size() > 1) st.pop();

        return st.top();
    }
};