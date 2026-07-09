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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if (list1 == NULL) return list2;
        if (list2 == NULL) return list1;
        
        ListNode* p = list1;
        ListNode* q = list2;
        
        ListNode* head = NULL;
        ListNode* tail = NULL;
        
        if (p->val <= q->val) {
            head = p;
            p = p->next;
        }
        else {
            head = q;
            q = q->next;
        }
        
        tail = head;
        
        while (p != NULL && q != NULL) {
            
            if (p->val <= q->val) {
                tail->next = p;
                p = p->next;
            }
            else {
                tail->next = q;
                q = q->next;
            }
            
            tail = tail->next;
        }
        
        if (p != NULL) {
            tail->next = p;
        }
        else {
            tail->next = q;
        }
        
        return head;
    }
};
