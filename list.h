#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.h"
#include "iterator.h"

using namespace std;

template <typename T>
class List {
    private:
        Node<T>* head;
        Node<T>* tail;
        int nodes;

        void print_reverse(Node<T>* head);

    public:
        List();

        T front(){return head -> data;};
        T back(){return tail -> data;};
        void push_front(T value){
            Node<T>*temporal = new Node<T>;
            temporal -> data = value;
            if(empty()){
                tempor -> next = nullptr;
                head = temporal;
                tail = temporal;
            }
            else{
                head -> next = head;
                head = temporal;
            }
        };
        void push_back(T value){
            Node<T>* temporal = new Node<T>;
            temporal -> data = value;
            temporal -> next = nullptr;
            if(empty){
                head=temporal;
                tail=temporal;
            }
            else{
                tail -> next = temporal;
                tail = temporal;
            }
        };
        void pop_front(){
            Node<T>*
        };
        void pop_back();
        T get(int position);
        void concat(List<T> &other);
        bool empty();
        int size();
        void print();
        void print_reverse();
        void clear();
        Iterator<T> begin();
        Iterator<T> end();

        ~List();
};
#endif
