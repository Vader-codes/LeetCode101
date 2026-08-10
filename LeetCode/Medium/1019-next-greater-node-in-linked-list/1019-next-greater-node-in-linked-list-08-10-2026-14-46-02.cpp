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
public:
    vector<int> nextLargerNodes(ListNode* head) {

        ListNode* newHead = reverse_list(head);
        ListNode* temp = newHead;
        vector<int>ans;
        stack<int>st;

        while(temp){
            if(st.empty())ans.push_back(0);

            else if(st.top() > temp->val) ans.push_back(st.top());

            else {
                while(!st.empty() && st.top() <= temp->val)st.pop();

                ans.push_back(st.empty() ? 0 : st.top());
            }

            st.push(temp->val);

            temp = temp->next;
        }
        head = reverse_list(newHead);
        reverse(ans.begin(), ans.end());
        return ans;        
    }
};