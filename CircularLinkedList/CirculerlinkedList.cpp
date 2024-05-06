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
    int size =0;
public:
    CircularLinkedList(int A[], int n);
    void Display();
    void recursiveDisplay(NodeC* p);
    void Insert(int index,int element);
    NodeC* getHead(){ return head; }
    void Delete(int index);
    int getSize();
    ~CircularLinkedList();


};

CircularLinkedList::CircularLinkedList(int *A, int n) {

    NodeC* t;
    NodeC* tail;

    head = new NodeC;

    head->data = A[0];
    size++;
    head->next = head;
    tail = head;

    for (int i=1; i<n; i++){
        size++;
        t = new NodeC;
        t->data = A[i];
        t->next = tail->next;
        tail->next = t;
        tail = t;
    }
}

void CircularLinkedList::Display() {
    NodeC* p = head;
    if(head !=NULL){
    do {
        cout << p->data << " -> " << flush;
        p = p->next;
    } while (p != head);
    cout << endl;
    }
}

void CircularLinkedList::recursiveDisplay(NodeC *p) {
    static int flag = 0;
    if ((p != head || flag == 0) && head){
        flag = 1;
        cout << p->data << " -> " << flush;
        recursiveDisplay(p->next);
    }
    flag = 0;
}

CircularLinkedList::~CircularLinkedList() {
    if(head){
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
}
void CircularLinkedList::Delete(int index){
    if (index==0){
        NodeC *p=head, *temp;
        while(p->next!=head){
            p=p->next;
        }
        if(p==head){
            size=0;
            delete head;
            head=NULL;
        }else {
            size--;
            temp = p->next;
            p->next = temp->next;
            head = p->next;
            delete temp;
        }
    }else{
        NodeC* p=head;
        size--;
        for(int i = 0; i < index-1; i++){
            p=p->next;
        }
        NodeC* temp = p->next;
        p->next=temp->next;
        delete temp;

    };
}
int CircularLinkedList::getSize(){
    return size;
};
void CircularLinkedList::Insert(int index, int element) {
    NodeC* p = head;
    NodeC *t = new NodeC();
    t->data=element;
    t->next=NULL;
    size++;
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


//int main() {
//
//    int A[] = {1};
//
//    CircularLinkedList cl(A, 1);
//    cl.Insert(0, 2);
//    cl.Insert(0, 3);
//    cl.Insert(0, 4);
//    cl.Insert(0, 5);
//    cl.Insert(0, 6);
//    cl.Insert(0, 7);
//    cl.Display();
//    cout<<"Size = "<<cl.getSize()<<"\n";
//    cl.Delete(0);
//    cl.Delete(0);
//    cl.Delete(0);
//    cl.Delete(0);
//    cl.Delete(0);
//    cl.Delete(0);
//    cout<<cl.getSize()<<"\n";;
//    cl.Delete(0);
//    cout<<cl.getSize()<<"\n";
//    cl.Display();
//    cout<<cl.getSize()<<"\n";
//    return 0;
//}