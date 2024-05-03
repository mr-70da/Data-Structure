#include <iostream>
using namespace std;

class NodeC{
public:
    int data;
    NodeC* next;
};

class CircularLinkedList{
private:
    NodeC* head;
public:
    CircularLinkedList(int A[], int n);
    void Display();
    void recursiveDisplay(NodeC* p);
    void Insert(int index,int element);
    NodeC* getHead(){ return head; }
    ~CircularLinkedList();


};

CircularLinkedList::CircularLinkedList(int *A, int n) {

    NodeC* t;
    NodeC* tail;

    head = new NodeC;

    head->data = A[0];
    head->next = head;
    tail = head;

    for (int i=1; i<n; i++){
        t = new NodeC;
        t->data = A[i];
        t->next = tail->next;
        tail->next = t;
        tail = t;
    }
}

void CircularLinkedList::Display() {
    NodeC* p = head;
    do {
        cout << p->data << " -> " << flush;
        p = p->next;
    } while (p != head);
    cout << endl;
}

void CircularLinkedList::recursiveDisplay(NodeC *p) {
    static int flag = 0;
    if (p != head || flag == 0){
        flag = 1;
        cout << p->data << " -> " << flush;
        recursiveDisplay(p->next);
    }
    flag = 0;
}

CircularLinkedList::~CircularLinkedList() {
    NodeC* p = head;
    while (p->next != head){
        p = p->next;
    }

    while (p != head){
        p->next = head->next;
        delete head;
        head = p->next;
    }

    if (p == head){
        delete head;
        head = nullptr;
    }

}

void CircularLinkedList::Insert(int index, int element) {
    NodeC* p = head;
    NodeC *t = new NodeC();
    t->data=element;
    t->next=NULL;
    if(index==0){
        if(head==NULL){
            head=t;
            head->next=head;
        }else{
            while(p->next!=head) p = p->next;
            p->next = t;
            t->next = head;
            head = t;
        }
    }else{
        for(int i = 0; i < index-1; i++){
                p=p->next;
        }t->next=p->next;
        p->next=t;

    }
}


int main() {

    int A[] = {1};

    CircularLinkedList cl(A, 1);
    cl.Insert(0, 9);

    cl.Display();

    NodeC* h = cl.getHead();
    cl.recursiveDisplay(h);

    return 0;
}