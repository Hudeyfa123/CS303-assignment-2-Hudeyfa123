#include "SingleLinkedList.h"

template<typename T>
Single_Linked_List<T>::Single_Linked_List() : head(nullptr), tail(nullptr), num_items(0) {}

template<typename T>
Single_Linked_List<T>::~Single_Linked_List() {
    while (!empty()) {
        pop_front();
    }
}

template<typename T>
void Single_Linked_List<T>::push_front(const T& item) {
    Node* new_node = new Node(item);
    if (empty()) {
        head = tail = new_node;
    } else {
        new_node->next = head;
        head = new_node;
    }
    num_items++;
}

template<typename T>
void Single_Linked_List<T>::push_back(const T& item) {
    Node* new_node = new Node(item);
    if (empty()) {
        head = tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
    num_items++;
}

template<typename T>
void Single_Linked_List<T>::pop_front() {
    if (!empty()) {
        Node* old_head = head;
        head = head->next;
        delete old_head;
        num_items--;
        if (empty()) tail = nullptr;
    }
}

template<typename T>
void Single_Linked_List<T>::pop_back() {
    if (!empty()) {
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node* prev = head;
            while (prev->next != tail) {
                prev = prev->next;
            }
            delete tail;
            tail = prev;
            tail->next = nullptr;
        }
        num_items--;
    }
}

template<typename T>
T Single_Linked_List<T>::front() const {
    if (!empty()) return head->data;
    throw std::out_of_range("List is empty");
}

template<typename T>
T Single_Linked_List<T>::back() const {
    if (!empty()) return tail->data;
    throw std::out_of_range("List is empty");
}

template<typename T>
bool Single_Linked_List<T>::empty() const {
    return num_items == 0;
}

template<typename T>
size_t Single_Linked_List<T>::size() const {
    return num_items;
}

template<typename T>
void Single_Linked_List<T>::insert(size_t index, const T& item) {
    if (index >= num_items) {
        push_back(item);
        return;
    }

    if (index == 0) {
        push_front(item);
        return;
    }

    Node* new_node = new Node(item);
    Node* current = head;
    for (size_t i = 0; i < index - 1; ++i) {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
    num_items++;
}

template<typename T>
bool Single_Linked_List<T>::remove(size_t index) {
    if (index >= num_items) return false;

    if (index == 0) {
        pop_front();
        return true;
    }

    Node* current = head;
    for (size_t i = 0; i < index - 1; ++i) {
        current = current->next;
    }

    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
    num_items--;

    if (current->next == nullptr) tail = current;

    return true;
}

template<typename T>
size_t Single_Linked_List<T>::find(const T& item) const {
    Node* current = head;
    size_t index = 0;
    while (current != nullptr) {
        if (current->data == item) return index;
        current = current->next;
        index++;
    }
    return num_items;
}
