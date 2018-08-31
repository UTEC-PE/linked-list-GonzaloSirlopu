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
        List(); // No se implementó

        T front(){
            if(!head){throw "lista vacia";}
            return head -> data;
        };
        T back(){
            if(!tail){throw "lista vacia";}
            return tail -> data;
        };
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
            if(empty){ // Qué es empty? Esto no va a compilar
                head=temporal;
                tail=temporal;
            }
            else{
                tail -> next = temporal;
                tail = temporal;
            }
        };
        void pop_front(){ // No se verifica si la lista está vacía
            Node<T>* temporal = head;
            head -> next = head;
            delete temporal;
        };
        void pop_back(){
            auto*temporal=head;
            if(!head){throw "list";}
            if(node==1){head=tail=nullptr;}
            else{
                while(temporal -> next != tail)
                    temporal=temporal->next;
                    tail=temporal;
            }
            delete temporal;
            node--;
        };

        T get(int position){
            try{
                if(position >= nodes){
                    if(position==0){return head->data;}
                }
                else if(position==nodes-1){return tail -> data;}
                else{
                    Node<T>*temporal=head;
                    while(position--){temporal=temporal->next;}
                    return temporal -> data;
                }
            }
        };
        void concat(List<T> &other){ // Y si alguna lista está vacía?
            this -> tail -> next =other -> head; // Other es un objeto, no un puntero. Esto no va a compilar
            this -> tail = other -> tail;
        };
        bool empty(){return head==nullptr;};
        int size(){ // No se implementó

        };
        void print(){ // No se implementó

        };
        void print_reverse(){ // No se implementó
            if(!head){throw "Empty";}
        };
        void clear(){ // No es tan simple, debes dar delete a todos los elementos 
            head=nullptr;
            tail=nullptr;
            nodes=0;
        };
        Iterator<T> begin();
        Iterator<T> end();

        ~List(); // No se implementó
};
#endif
