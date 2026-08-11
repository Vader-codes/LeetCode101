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
    void reverse_nodes(vector<TreeNode*>nodes){
        int i=0, j=nodes.size()-1;

        while(  i < j){
            swap(nodes[i]->val, nodes[j]->val);
            i++;
            j--;
        }
    }
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root)return root;

        queue<TreeNode*>q;
        q.push(root);

        int level =0;

        while(!q.empty()){

            int size = q.size();

            vector<TreeNode*>nodes;
            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();

                nodes.push_back(node);
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            if(level %2 !=0){
                reverse_nodes(nodes);
            }
            level++;
        }
        return root;
    }
};