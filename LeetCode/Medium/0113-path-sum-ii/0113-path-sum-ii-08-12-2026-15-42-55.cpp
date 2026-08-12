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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        // first do this with the bfs                        //first //second
        queue<pair<TreeNode*, pair<int, vector<int>>>>
            q; // {{node}, {cursum, currpath}}

        q.push({root, {root->val, {root->val}}});
        while (!q.empty()) {
            int size = q.size();

            auto[node, data] = q.front(); q.pop();
            int curSum = data.first;
            vector<int>path = data.second;

            // path must end at leaf node
            if(!node->left && !node->right){
                if(curSum == targetSum)ans.push_back(path);
            }

            if(node->left){
               path.push_back(node->left->val);
               q.push({node->left, {curSum+node->left->val, path}});
               path.pop_back(); // do not change the path
            }
             if(node->right){
               path.push_back(node->right->val);
               q.push({node->right, {curSum+node->right->val, path}});
               path.pop_back(); // do not change the path
            }
        }

        return ans;
    }
};