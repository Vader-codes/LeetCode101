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
private:
    ListNode* reverse_list(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* temp = head;
        while (temp) {
            ListNode* next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        return prev;
    }

public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while (temp && temp->next) {
            // pair of nodes
           ListNode* first = temp;
           ListNode* second = temp->next;

           // head of remaining list
           ListNode* next = second->next;

           // cut the link 
           second->next = nullptr;

           // reverse the pairs
           ListNode* newHead = reverse_list(first);
           if(prev == nullptr){
            // need to update the head
            head = newHead;
           }
           else{
             prev->next = newHead;
           }
           // after reversal first is the tail of revered pair
           first->next = next; // joined the list again
           // move pointers
           prev = first;
           temp = next;  
        }
        return head;
    }
};