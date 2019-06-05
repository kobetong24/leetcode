#include <iostream>

class Node{
    public:
        int value;
        Node* next = NULL;
        Node(int _value);
        ~Node();
};

Node* head;
Node* tail;


Node::Node(int _value){
    value = _value;
    if (head == NULL){head = this;}
    if (tail == NULL){tail = this;}
    else{
        tail->next = this;
        tail = tail->next;
    }
}

void displayNode(){
    Node* ptr;
    ptr = head;
    while (ptr->next != NULL){
        //display head
        cout << "Node->val:" << ptr->value << endl;
        ptr = ptr->next;
    }
    cout << "Node->val:" << ptr->value << endl;
}

void reverseLink(Node* _head, Node* _tail){
    Node* reverse;
    Node* temp;
    Node* list_to_do;
    
    reverse = _head;
    list_to_do = _head->next;
    reverse->next = _tail->next;
    
    while (list_to_do->next != NULL){
        temp = list_to_do->next;
        list_to_do->next = reverse;
        reverse = list_to_do;
        list_to_do = temp;
    }
    list_to_do->next = reverse;
    reverse = list_to_do;
    head = _tail;
    tail = _head;
}

int main() {
    vector<int> input = {1,2,3,4,5};
    Node* node;
    for (int i = 0 ; i < input.size() ; i++){
        node = new Node(input.at(i));
    }
    displayNode();
    out << "---------------after reversed---------------" << endl;
    reverseLink(head,tail);
    displayNode();
    
}
