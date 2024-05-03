//
// Created by mahmoud on 4/20/2024.
//
#include <bits/stdc++.h>
using namespace std;
#ifndef SINGLELINKEDLIST_SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_SINGLELINKEDLIST_H
template<typename T>

class NodeS{

public:
    T data;
    NodeS<T> *next;
    NodeS();
};

template<typename T>
class SingleLinkedLIst {
    private:
        int size;
        NodeS<T> *first;
        NodeS<T> *last;
    public:
        SingleLinkedLIst();    //tested
        SingleLinkedLIst(T array[],int size);    //tested
        void display();    //tested
        void insertAtHead(T element);    //tested
        void insertAtTail (T element);    //tested
        void insertAt (T element, int index);    //tested
        void removeAtHead ();    //tested
        void removeAtTail ();    //tested
        void removeAt (int index); //tested
        T retrieveAt (int index); //tested
        void replaceAt (T newElement, int index); //tested
        bool isExist (T element); //tested
        bool isItemAtEqual (T element, int index);  //tested
        void swap (int firstItemIdx, int secondItemIdx); //under developing
        bool isEmpty (); //tested
        int linkedListSize (); //tested
        void clear ();//tested
        void print (); //tested

};


#endif //SINGLELINKEDLIST_SINGLELINKEDLIST_H
