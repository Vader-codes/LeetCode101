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
    ListNode* partition(ListNode* head, int x) {
     ListNode smallDummy(0);
     ListNode largeDummy(0);

     ListNode* small = &smallDummy;
     ListNode* large = &largeDummy;

     ListNode* cur = head;

     while(cur){
        if(cur->val < x){
            small->next = cur;
             small = small->next;
        }
        else{
            large->next = cur;
            large = large->next;
        }
        cur = cur->next;
     }
     // end the line
     large->next = nullptr;
     small->next = largeDummy.next;
     return smallDummy.next;

    }
};