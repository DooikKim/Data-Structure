#include <iostream>

template <class T>
class Node {
    private:
        T data;
        Node *next = nullptr;
    public:
        Node() {}
        Node(T _data) {
            data = _data;
        }
        void pointNode(Node<T> node) {
            this->next = node;
        }
}

template <class T>
class List {
    public:
        List() { 

            
