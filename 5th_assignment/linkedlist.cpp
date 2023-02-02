#include <iostream>

using namespace std;

struct Node{
    int num;
    Node* next;
};

class LinkedList{
    public:
        LinkedList();
        LinkedList(int num1);
        LinkedList(int num1, int num2);
        
        Node* head;
        
        int show();
        int append(int num, Node* curr);
};

LinkedList::LinkedList(){
    head->num = 0;
    head->next = NULL;
}


LinkedList::LinkedList(int num1){
    head->num = num1;
    head->next = NULL;
}


LinkedList::LinkedList(int num1, int num2){
    Node* curr = LinkedList(num2);
    head->num = num1;
    head->next = curr;
}

LinkedList::~LinkedList(){
    Node* curr = head;
    while (curr->next != NULL){
        Node* temp = curr;
        curr = curr->next;
        temp = NULL;
        delete temp;
    }
    curr = NULL;
    delete curr;
}

int LinkedList::show(){
    Node* curr = head;
    while (curr->next != NULL){
        cout << curr << endl;
        curr = curr->next;
    }
    cour << curr << endl;
}

int LinkedList::append(int add, Node* curr){
    if (curr == NULL){
        return -1;
    }
    if (curr->next != NULL){
        return LinkedList.append(add, curr->next);
    }
    else{
        curr->next = LinkedList(add);
        return 0;
    }
}


int main(){

    return 0;
}