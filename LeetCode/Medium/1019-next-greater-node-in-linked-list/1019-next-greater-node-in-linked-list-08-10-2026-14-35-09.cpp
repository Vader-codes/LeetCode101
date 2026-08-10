/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* mover = head;
        vector<int>ans;
        while(mover){

            ListNode* temp = mover->next;
            int greater =0;
            while(temp){
                if(temp->val > mover->val){
                    greater = temp->val;
                    break;
                }
                else temp = temp->next;
            }
            ans.push_back(greater);
            mover = mover->next;

        }
        return ans;

    }
};