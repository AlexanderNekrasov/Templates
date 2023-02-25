---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':heavy_check_mark:'
    path: template/util.hpp
    title: template/util.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/template.hpp\"\n#ifdef PRAGMAS\n#pragma GCC optimize(\"\
    Ofast,unroll-loops,fast-math,inline,no-stack-protector\")\n#pragma GCC target(\"\
    sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt\")\n#endif\n#include\
    \ <algorithm>\n#include <array>\n#include <bitset>\n#include <chrono>\n#include\
    \ <codecvt>\n#include <complex>\n#include <condition_variable>\n#include <deque>\n\
    #include <exception>\n#include <forward_list>\n#include <fstream>\n#include <functional>\n\
    #include <future>\n#include <iomanip>\n#include <ios>\n#include <iosfwd>\n#include\
    \ <iostream>\n#include <istream>\n#include <iterator>\n#include <limits>\n#include\
    \ <list>\n#include <locale>\n#include <map>\n#include <memory>\n#include <mutex>\n\
    #include <new>\n#include <numeric>\n#include <ostream>\n#include <queue>\n#include\
    \ <random>\n#include <regex>\n#include <set>\n#include <sstream>\n#include <stack>\n\
    #include <stdexcept>\n#include <streambuf>\n#include <string>\n#include <thread>\n\
    #include <tuple>\n#include <typeinfo>\n#include <unordered_map>\n#include <unordered_set>\n\
    #include <utility>\n#include <valarray>\n#include <vector>\n\n#include <cassert>\n\
    #include <ccomplex>\n#include <cctype>\n#include <cerrno>\n#include <cfenv>\n\
    #include <cfloat>\n#include <cinttypes>\n#include <ciso646>\n#include <climits>\n\
    #include <clocale>\n#include <cmath>\n#include <csetjmp>\n#include <csignal>\n\
    #include <cstdarg>\n#include <cstdbool>\n#include <cstddef>\n#include <cstdint>\n\
    #include <cstdio>\n#include <cstdlib>\n#include <cstring>\n#include <ctgmath>\n\
    #include <ctime>\n#include <cwchar>\n#include <cwctype>\n\n#line 2 \"template/macro.hpp\"\
    \n\n#define all(v) (v).begin(),(v).end()\n#define rall(v) (v).rbegin(),(v).rend()\n\
    #define sz(v) (int((v).size()))\n#line 6 \"template/util.hpp\"\n\ntemplate<typename\
    \ T>\nvoid unq(std::vector<T> &arr) {\n    sort(all(arr));\n    arr.erase(unique(all(arr)),\
    \ arr.end());\n}\nvoid unq(std::string &arr) {\n    sort(all(arr));\n    arr.erase(unique(all(arr)),\
    \ arr.end());\n}\n#line 79 \"template/template.hpp\"\n\nusing namespace std;\n\
    \nusing ll = long long;\nusing ld = long double;\nusing ull = unsigned long long;\n\
    using uint = unsigned;\n\nnamespace Quark {\n    void solve();\n};\n\nint main()\
    \ { \n    ios_base::sync_with_stdio(0);\n    cin.tie(0);\n    cout.tie(0);\n \
    \   Quark::solve();\n}\n\n#line 2 \"template/main.cpp\"\n\nusing namespace Quark;\n\
    \n\nvoid Quark::solve() {\n}\n"
  code: '#include "template/template.hpp"


    using namespace Quark;



    void Quark::solve() {

    }

    '
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/util.hpp
  isVerificationFile: false
  path: template/main.cpp
  requiredBy: []
  timestamp: '2023-02-25 13:28:05+03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/main.cpp
layout: document
redirect_from:
- /library/template/main.cpp
- /library/template/main.cpp.html
title: template/main.cpp
---
