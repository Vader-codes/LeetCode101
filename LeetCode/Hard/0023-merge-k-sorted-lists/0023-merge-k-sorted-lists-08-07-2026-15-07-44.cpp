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
        if(lists.size() ==0)return NULL;
        typedef pair<int, ListNode*>p;

        priority_queue<p, vector<p>, greater<p>>pq;
        for(int i=0; i<lists.size(); i++){
            // we are pushing the head of each node into the pq {val, node}
            if(lists[i])
            pq.push({lists[i]->val, lists[i]});

        }

        ListNode dummy(-1);
        ListNode* temp = &dummy;

        while( !pq.empty()){
            auto[val, node]= pq.top();
            pq.pop();
            temp->next = node;
            temp = temp->next;

            if(node->next)pq.push({node->next->val, node->next});
        }
        return dummy.next;
    }
};