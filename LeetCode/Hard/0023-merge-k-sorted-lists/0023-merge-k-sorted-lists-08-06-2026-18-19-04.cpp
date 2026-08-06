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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>temp;
        for(int i =0; i<lists.size(); i++){
            ListNode* curr = lists[i];
            while(curr){
                temp.push_back(curr->val);
                curr = curr->next;
            }
        }
        // sort the temp
        sort(temp.begin(), temp.end());

        // make a new sorted linked list
        ListNode dummy(-1);
        ListNode* mover = &dummy;

        for(int i=0; i<temp.size(); i++){
            ListNode* node = new ListNode(temp[i]);
            mover->next = node;
            mover= mover->next;
        }
        return dummy.next;


         
    }
};