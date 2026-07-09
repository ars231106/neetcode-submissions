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

    ListNode* reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;

        while(curr != NULL){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = reverse(head);

        if(n == 1){
            ListNode* p = temp;
            temp = temp -> next;
            delete p;
        }

        else{
            ListNode* p = temp;
            for(int i = 1; i<n-1; i++){
                p = p -> next;
            }
            ListNode* q = p->next;
            p -> next = q -> next;
            delete q;
        }

        head = reverse(temp);
        return head;
    }
};
