//
// Created by mahmoud on 4/20/2024.
//
#include "SingleLinkedLIst.h"
template<typename T>
NodeS<T>::NodeS() {
    this->data=0;
    this->next=NULL;
}
template<typename T>
SingleLinkedLIst<T>::SingleLinkedLIst(){
    this->first=NULL;
    this->last=NULL;
    this->size=0;
};
template<typename T>
SingleLinkedLIst<T>::SingleLinkedLIst(T array[],int arraySize){//time o(n) space o(n)
    this->size=1;
    NodeS<T> *newNodeS;
    first=new NodeS<T>;
    first->data=array[0];
    first->next=NULL;
    last=first;
    for(int i = 1; i<arraySize; i++)
    {
        newNodeS =new NodeS<T>;
        newNodeS->data=array[i];
        newNodeS->next=NULL;
        last->next=newNodeS;
        last=newNodeS;
        size++;
    }
};

template<typename T>
void SingleLinkedLIst<T>::insertAtHead(T element){ //time o(1) space o(1)
    NodeS<T> *newNodeS = new NodeS<T>();
    newNodeS->data = element;
    newNodeS->next = NULL;
    if(first){
        newNodeS->next=first;
        first=newNodeS;
    }else{
        first=last=newNodeS;
    }size++;
};
template<typename T>
void SingleLinkedLIst<T>::insertAtTail (T element){
    NodeS<T> *newNodeS = new NodeS<T>();
    newNodeS->data = element;
    newNodeS->next = NULL;
    if(last){
        last->next=newNodeS;
        last=newNodeS;
    }else{
        first=last=newNodeS;
    }size++;
};
template<typename T>
void SingleLinkedLIst<T>:: insertAt (T element, int index){
    NodeS<T> *newNodeS = new NodeS<T>();
    newNodeS->data = element;
    newNodeS->next = NULL;
    NodeS<T> *postion=first;
    if(index<0 or size<index){
        throw out_of_range("Index is out of scope");
    }else if(index==0){
        newNodeS->next=first;
        first=newNodeS;
        size++;
    }else{
        NodeS<T> *postion=first;
        for(int i =0 ; i<index-1;i++){
            postion=postion->next;
        }
        newNodeS->next=postion->next;
        postion->next=newNodeS;
        size++;
        if(index==(size-1)){
            last=postion;
        }

    }
};
template<typename T>
void SingleLinkedLIst<T>:: removeAtHead(){
    if(!size){
        throw out_of_range("The list is already empty!");
    }else if(size==1){
        first=last=NULL;
        size--;
    }else{
        NodeS<T> *temp =first;
        first=first->next;
        delete temp;
        size--;
    }
};
template<typename T>
void SingleLinkedLIst<T>:: removeAtTail (){
    if(!size){
        throw out_of_range("The list is already empty!");

    }else if(size==1){
        first=last=NULL;
        size--;
    }else{
        NodeS<T> *postion=first;
        for(int i =0 ; i<size-2;i++){
            postion=postion->next;
        }
        last=postion;
        postion=postion->next;
        delete postion;
        size--;
    }
};
template<typename T>
void SingleLinkedLIst<T> ::display() {
    NodeS<T> *postion=first;
    cout<<"List elements: ";
    for(int i =0; i<size;i++){
        cout<<postion->data<<" ";
        postion=postion->next;
    }cout<<"\n";
}
template<typename T>
void SingleLinkedLIst<T> ::removeAt(int index){
    NodeS<T> *postion=first;
    if(index<0 or size<index){
        throw out_of_range("Index is out of scope");
    }else if(index==1){
        postion=first;
        first=first->next;
        delete postion;
        size--;
    }else{
        NodeS<T> *postion=first,*temp=NULL;
        for(int i =0 ; i<index;i++){
            temp=postion;
            postion=postion->next;
        }
        temp->next=postion->next;
        if(index==(size-1)){
            last=postion;
        }
        size--;
    }
};
template<typename T>
T SingleLinkedLIst<T> :: retrieveAt (int index){
    if(index<0 or index>=size){
        throw out_of_range("Index is out of scope");
    }
    NodeS<T> *postion=first;
    for(int i =0 ; i<index;i++){
        postion=postion->next;
    }
    return postion->data;
};
template<typename T>
void SingleLinkedLIst<T> :: replaceAt (T newElement, int index){
    if(index<0 or size<=index){
        throw out_of_range("Index is out of scope");
    }else if(index==0){
        first->data=newElement;
    }else{
        NodeS<T> *postion=first;
        for(int i =0 ; i<index;i++){
            postion=postion->next;
        }postion->data=newElement;



    }
};
template<typename T>
bool SingleLinkedLIst<T> :: isExist (T element){
    NodeS<T> *postion=first;
    for(int i=0;i<size;i++){
        if(postion->data==element)
            return 1;
        postion=postion->next;

    }return 0;

};
template<typename T>
bool SingleLinkedLIst<T> ::isItemAtEqual (T element, int index){
    NodeS<T> *postion=first;
    if(index<0 or size<index){
        throw out_of_range("Index is out of scope");
    }else{
        for(int i=0;i<index;i++){
            postion=postion->next;
        }if(postion->data==element)
            return 1;
        return 0;
        };
    }

template<typename T>
void SingleLinkedLIst<T> ::swap (int firstItemIdx, int secondItemIdx){
    if(firstItemIdx<0 or size<=firstItemIdx){
        throw out_of_range("First index is out of scope");
    }else if(secondItemIdx<0 or size<=secondItemIdx){
        throw out_of_range("Second index is out of scope");
    }else{
        NodeS<T> *Fposition=first,*Sposition=first;
        for(int i =0 ;i<firstItemIdx;i++){
            Fposition=Fposition->next;
        }for(int i =0 ;i<secondItemIdx;i++){
            Sposition=Sposition->next;
        }
        T temp = Fposition->data;
        Fposition->data = Sposition->data;
        Sposition->data = temp;

    }
}
        template<typename T>
bool SingleLinkedLIst<T> :: isEmpty (){
    if(size==0)
        return 1;
    return 0;
};
template<typename T>
int SingleLinkedLIst<T> :: linkedListSize (){
    return size;
};
template<typename T>
void SingleLinkedLIst<T> ::clear (){
    NodeS<T> *postion=first;

    while (first){
        first=first->next;
        delete postion;
        postion=first;
    }last=size=0;

};
template<typename T>
void SingleLinkedLIst<T> ::print (){
    NodeS<T> *postion=first;
    cout<<"List elements: ";
    for(int i =0; i<size;i++){
        cout<<postion->data<<" ";
        postion=postion->next;
    }cout<<"\n";

};


