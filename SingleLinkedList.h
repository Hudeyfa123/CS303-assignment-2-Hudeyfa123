#pragma once
#include <iostream>

template<typename T>
class Single_Linked_List {
private:
    struct Node {
        T data;
        Node* next;
        Node(T data) : data(data), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t num_items;

public:
    Single_Linked_List();
    ~Single_Linked_List();

    void push_front(const T& item);
    void push_back(const T& item);
    void pop_front();
    void pop_back();
    T front() const;
    T back() const;
    bool empty() const;
    size_t size() const;
    void insert(size_t index, const T& item);
    bool remove(size_t index);
    size_t find(const T& item) const;
};
