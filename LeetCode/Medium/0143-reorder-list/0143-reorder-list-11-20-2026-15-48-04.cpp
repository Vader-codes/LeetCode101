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
    void reorderList(ListNode* head) {
        if(!head)return;

        // step 1 find the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!= nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        // now divide the linked list into two halves and reverse the second half
        ListNode* second = slow->next;
        ListNode* prev = slow->next = nullptr;
        while(second){
            ListNode* next = second->next;
            second->next = prev;
            prev = second;
            second = next;
        }
        // Now merge two linked lists
        ListNode* first = head;
        second = prev;
        while(second){
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;
            first->next = second;
            second->next = tmp1;
            first = tmp1;
            second = tmp2;


        }
        
    }
};