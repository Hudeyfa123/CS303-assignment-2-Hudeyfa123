#include "StackUsingVector.h"
#include <stdexcept>
#include <numeric>

void Stack::push(int value) {
    data.push_back(value);
}

void Stack::pop() {
    if (!empty()) {
        data.pop_back();
    } else {
        throw std::out_of_range("Stack is empty");
    }
}

int Stack::top() const {
    if (!empty()) {
        return data.back();
    } else {
        throw std::out_of_range("Stack is empty");
    }
}

bool Stack::empty() const {
    return data.empty();
}

size_t Stack::size() const {
    return data.size();
}

double Stack::average() const {
    if (empty()) {
        throw std::out_of_range("Stack is empty");
    }
    int sum = std::accumulate(data.begin(), data.end(), 0);
    return static_cast<double>(sum) / data.size();
}
