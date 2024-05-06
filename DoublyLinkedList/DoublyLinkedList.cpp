#include <iostream>
using namespace std;
class NodeD{
    public:
        NodeD* prev;
        int data;
        NodeD* next;
};
class DoublyLinkedList{
    private:
        NodeD* head;
        int size = 0;
    public:
    DoublyLinkedList();
    DoublyLinkedList(int A[], int n);
    ~DoublyLinkedList();
    void Display();
    int getSize();
    void Insert(int index, int x);
    void Reverse();
};
DoublyLinkedList::DoublyLinkedList() {
    head = new NodeD;
    head->prev = nullptr;
    head->data = 0;
    head->next = nullptr;
}
DoublyLinkedList::DoublyLinkedList(int A[], int n){
    head = new NodeD;
    head->prev = nullptr;
    head->data = A[0];
    size++;
    head->next = nullptr;
    NodeD* tail = head;

    for (int i=1; i<n; i++){
        size++;
        NodeD* t = new NodeD;
        t->prev = tail;
        t->data = A[i];
        t->next = tail->next;
        tail->next = t;
        tail = t;
    }
}void DoublyLinkedList::Display(){
    NodeD *postion = head;
    cout<<"List elements: ";
    for(int i =0; i<size;i++){
        cout<<postion->data<<" ";
        postion=postion->next;
    }cout<<"\n";

}
DoublyLinkedList::~DoublyLinkedList() {
    NodeD* p = head;
    while (head){
        head = head->next;
        delete p;
        p = head;
    }
}
int DoublyLinkedList::getSize(){
    return size;
}
void DoublyLinkedList::Insert(int index, int x){
    NodeD *newNode=new NodeD;
    newNode->data = x;
    if (index < 0 || index > size){
        throw out_of_range("");
    }size++;
    if(index == 0){
        NodeD *postion = head;
        head=newNode;
        newNode->prev = NULL;
        newNode->next = postion;
    }else{
        NodeD *postion=head;
        for(int i = 0; i < index-1; i++){
            postion=postion->next;
        }
        newNode->prev=postion;
        newNode->next=postion->next;
        postion->next->prev=newNode;
        postion->next=newNode;
    }
}


void DoublyLinkedList::Reverse() {
    NodeD* p = head;
    NodeD* temp;
    while (p != nullptr){
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;

        if (p->next == nullptr){
            p->next = p->prev;
            p->prev = nullptr;
            head = p;
            break;
        }
    }
}

int main() {
    DoublyLinkedList dll;
    cout << "Length: " << dll.getSize() << endl;
    dll.Display();
    dll.Insert(0, 11);

    dll.Display();

    dll.Display();

    return 0;
}