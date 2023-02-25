#pragma once
#include "macro.hpp"
#include <vector>
#include <algorithm>
#include <string>

template<typename T>
void unq(std::vector<T> &arr) {
    sort(all(arr));
    arr.erase(unique(all(arr)), arr.end());
}
void unq(std::string &arr) {
    sort(all(arr));
    arr.erase(unique(all(arr)), arr.end());
}
