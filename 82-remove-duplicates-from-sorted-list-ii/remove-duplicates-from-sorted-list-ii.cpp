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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prev = new ListNode(0);
        prev -> next = head;

        ListNode* curr = head;
        ListNode* last = prev;


        while(curr){
            if(curr -> next && curr -> val == curr -> next -> val){
                int val = curr -> val;


                while(curr && curr -> val == val){
                    ListNode* temp = curr;

                    curr = curr -> next;
                    delete temp;
                }


                last -> next = curr;
            }
            else{
                last = curr;
                curr = curr -> next;
            }
        }

        return prev -> next;
    }
};