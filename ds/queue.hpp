#pragma once

template<typename T>
struct simple_queue {
    vector<T> arr;
    int pos = 0;
    void reserve(int n) { arr.reserve(n); }
    int size() const { return sz(arr) - pos; }
    bool empty() { return pos == sz(arr); }
    void push(const T& t) { arr.push_back(t); }
    T& front() {
        return arr[pos];
    }
    void clear() {
        arr.clear();
        pos = 0;
    }
    void pop() { pos++; }
};
