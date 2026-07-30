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
    ListNode* reverse_list(ListNode* head){
        ListNode* prev = NULL;
        ListNode* temp = head;
        while(temp){
            ListNode* next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        return prev;
    }
    private:
    ListNode* find_kth_node(ListNode* temp , int k){
        while( temp && k > 0){
            k--;
            temp = temp->next;
        }
        return temp;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || !head->next)return head;

        // make a temp and prev and next node
        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp){
            // step 1: find the kth node
            ListNode* kth_node = find_kth_node(temp, k-1);
            // check if the node is null means no nodes to reverse
            if(kth_node == NULL){
                // check if prev exists
                if(prev){
                    prev->next = temp;
                    break;
                }
            }
            // if we found the kth node 
            ListNode* next = kth_node->next;
            kth_node->next = nullptr; // cutt off the list
            ListNode* newHead = reverse_list(temp);

            // check if the group is first then need to update the head
            if(head == temp){
                head = newHead;
            }
            else{
                prev->next = newHead;

            }
            prev = temp;
            temp = next;
        }
        return head;
    }

};