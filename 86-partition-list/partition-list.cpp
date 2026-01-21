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
        ListNode* less = new ListNode(0);
        ListNode* great = new ListNode(0);


        ListNode* les = less;
        ListNode* gr = great;


        while(head){
            if(head -> val < x){
                les -> next = head;
                les = les -> next;
            }
            else{
                gr -> next = head;
                gr = gr -> next;
            }

            head = head -> next;
        }
        gr->next = nullptr;


        les -> next = great -> next;

        return less -> next;
        
    }
};