#include <iostream>
#include "SingleLinkedList.cpp"  
#include "StackUsingVector.h"

int main() {
    // Test Single_Linked_List
    Single_Linked_List<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_front(5);

    std::cout << "List front: " << list.front() << "\n";
    std::cout << "List back: " << list.back() << "\n";
    std::cout << "List size: " << list.size() << "\n";

    list.pop_front();
    std::cout << "List front after pop: " << list.front() << "\n";

    // Test Stack
    Stack stack;
    stack.push(5);
    stack.push(10);
    stack.push(15);

    std::cout << "Stack top: " << stack.top() << "\n";
    std::cout << "Stack average: " << stack.average() << "\n";
    std::cout << "Stack size: " << stack.size() << "\n";

    stack.pop();
    std::cout << "Stack top after pop: " << stack.top() << "\n";

    return 0;
}
