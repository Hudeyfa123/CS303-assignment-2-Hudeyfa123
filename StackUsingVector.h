#pragma once
#include <vector>

class Stack {
private:
    std::vector<int> data;

public:
    void push(int value);
    void pop();
    int top() const;
    bool empty() const;
    std::size_t size() const;
    double average() const;
};
