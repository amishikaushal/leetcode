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

        while(temp){
            Node* newNode = new Node(temp -> val);

            Node* nextNode = temp -> next;

            temp -> next = newNode;
            newNode -> next = nextNode;

            temp = nextNode;
        }
    }

    void connect(Node* head){
        Node* temp = head;

        while(temp){
            Node* copy = temp -> next;

            if(temp -> random){
                copy -> random = temp -> random -> next;
            }
            else{
                copy -> random = nullptr;
            }

            temp = copy -> next;
        }
    }

    Node* insert(Node* head){
        Node* temp = head;
        Node* dummy = new Node(-1);

        Node* res = dummy;


        while(temp){
             Node* copy = temp -> next;

             res -> next = copy;

             res = res -> next;

             temp -> next = temp -> next -> next;


             temp = temp -> next;

        }
        return dummy -> next;

    }



    Node* copyRandomList(Node* head) {
         if(!head) return nullptr;

        insertNext(head);

        connect(head);

        return insert(head);
    }
};