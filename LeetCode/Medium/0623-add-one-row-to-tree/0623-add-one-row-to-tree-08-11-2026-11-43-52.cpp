/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (!root)
            return root;
        int level = 1;
        // edge case
        if(depth == 1){
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();

            if (level == depth - 1) {
                // each node of this level should have a new row
                for (int i = 0; i < size; i++) {
                    TreeNode* node = q.front();
                    q.pop();

                    TreeNode* oldLeft = node->left;
                    TreeNode* oldRight = node->right;

                    node->left = new TreeNode(val);
                    node->right = new TreeNode(val);

                    node->left->left = oldLeft;
                    node->right->right = oldRight;

                }
                    break;
            }
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            level++;
        }
        return root;
    }
};