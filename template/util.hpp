#pragma once
#include "macro.hpp"
#include <vector>
#include <algorithm>

template<typename T>
void unq(std::vector<T> &arr) {
    sort(all(arr));
    arr.erase(unique(all(arr)), arr.end());
}
