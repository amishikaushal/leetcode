/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertNext(Node* head){
        Node* temp = head;

        while(temp != nullptr){
            Node* copy = new Node(temp -> val);

            Node* next = temp -> next;
            copy -> next = next;

            temp -> next = copy;

            temp = next;
        }
    }

    void copyrandom(Node* head){
        Node* temp = head;


        while(temp != nullptr){
            Node* copy = temp -> next;

            if(temp -> random){
                copy -> random = temp -> random -> next;
            }
            else{
                copy -> random = nullptr;
            }

             temp = temp->next->next;
        }
       

    }

    Node* insert(Node* head){
        Node* dummy = new Node(-1);
        Node* res = dummy;
        Node* curr = head;


        while(curr != nullptr){
            res->next = curr->next;
            res = res->next;

           
            curr->next = curr->next->next;
            
            curr = curr->next;

        }
        return dummy->next;
    }
    Node* copyRandomList(Node* head) {
        if(!head){
            return nullptr;
        }
        insertNext(head);
        copyrandom(head);


        return insert(head);


    }
};