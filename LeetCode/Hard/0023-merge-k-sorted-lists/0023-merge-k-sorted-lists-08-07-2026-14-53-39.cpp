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
    ListNode* mergeNodes(ListNode* l1, ListNode* l2){
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        ListNode dummy(-1);
        ListNode* temp = &dummy;

        while(t1 && t2){
            if(t1->val < t2->val){
                temp->next = t1;
                temp = temp->next;
                t1 = t1->next;
            }
            else{
                temp->next = t2;
                temp = temp->next;
                t2 = t2->next;
            }
        }
        if(t1)temp->next= t1;
        else temp->next= t2;

        return dummy.next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)return NULL;

        ListNode* head = lists[0];
        for(int i=1; i<lists.size(); i++){
            head = mergeNodes(head, lists[i]);
        }
        return head;
        
    }
};