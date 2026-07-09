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
class Solution{
public:
    struct Compare{
        bool operator()(ListNode * a, ListNode * b){
            return a->val > b->val;  
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists){
        priority_queue<ListNode*,vector<ListNode*>,Compare> pq;

        for(int i = 0 ; i < lists.size() ; i++){
            if(lists[i] != NULL){
                pq.push(lists[i]);
            }
        }

        ListNode * head = NULL;
        ListNode * tail = NULL;

        while(!pq.empty()){
            ListNode * smallest = pq.top();
            pq.pop();

            if(head == NULL){
                head = smallest;
                tail = smallest;
            }
            else{
                tail->next = smallest;
                tail = smallest;
            }
            if(smallest->next != NULL){
                pq.push(smallest->next);
            }
        }

        return head;
    }
};
