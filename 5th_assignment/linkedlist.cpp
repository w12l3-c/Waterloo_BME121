#include <iostream>

using namespace std;

class LinkedList{
    public:
        LinkedList();
        LinkedList(int num1);
        LinkedList(int num1, int num2);
        ~LinkedList();

        
        LinkedList* next;
        int data;
        
        
        void print();
        void append(int num, LinkedList* curr);
};

LinkedList::LinkedList(){
    next = NULL;
    data = 0;
}


LinkedList::LinkedList(int num1){
    next = NULL;
    data = num1;
}


LinkedList::LinkedList(int num1, int num2){
    LinkedList* curr = new LinkedList();
    curr->data = num2;
    curr->next = NULL;
    next = curr;
    data = num1;
}

LinkedList::~LinkedList(){
    LinkedList* curr = this;
    while (curr->next != NULL){
        LinkedList* temp = curr;
        curr = curr->next;
        temp = NULL;
        delete temp;
    }
    curr = NULL;
    delete curr;
}

void LinkedList::print(){
    LinkedList* curr = this;
    while (curr->next != NULL){
        cout << curr << endl;
        curr = curr->next;
    }
    cout << curr << endl;
}

void LinkedList::append(int add, LinkedList* curr){
    if (curr == NULL){
        return;
    }
    if (curr->next != NULL){
        return append(add, curr->next);
    }
    else{
        curr->next->data = add;
        curr->next->next = NULL;
        return;
    }
}


int main(){
    LinkedList* link = new LinkedList();
    LinkedList* curr = link;
    for (int i = 0; i < 10; i++){
        link->append(i+1, curr);
    }
    link->print();
    return 0;
}