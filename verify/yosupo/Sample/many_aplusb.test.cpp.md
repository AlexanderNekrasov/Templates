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
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/many_aplusb
    links:
    - https://judge.yosupo.jp/problem/many_aplusb
  bundledCode: "#line 1 \"verify/yosupo/Sample/many_aplusb.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/many_aplusb\"\n#line 2 \"template/template.hpp\"\
    \n#ifdef PRAGMAS\n#pragma GCC optimize(\"Ofast,unroll-loops,fast-math,inline,no-stack-protector\"\
    )\n#pragma GCC target(\"sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt\"\
    )\n#endif\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include\
    \ <chrono>\n#include <codecvt>\n#include <complex>\n#include <condition_variable>\n\
    #include <deque>\n#include <exception>\n#include <forward_list>\n#include <fstream>\n\
    #include <functional>\n#include <future>\n#include <iomanip>\n#include <ios>\n\
    #include <iosfwd>\n#include <iostream>\n#include <istream>\n#include <iterator>\n\
    #include <limits>\n#include <list>\n#include <locale>\n#include <map>\n#include\
    \ <memory>\n#include <mutex>\n#include <new>\n#include <numeric>\n#include <ostream>\n\
    #include <queue>\n#include <random>\n#include <regex>\n#include <set>\n#include\
    \ <sstream>\n#include <stack>\n#include <stdexcept>\n#include <streambuf>\n#include\
    \ <string>\n#include <thread>\n#include <tuple>\n#include <typeinfo>\n#include\
    \ <unordered_map>\n#include <unordered_set>\n#include <utility>\n#include <valarray>\n\
    #include <vector>\n\n#include <cassert>\n#include <ccomplex>\n#include <cctype>\n\
    #include <cerrno>\n#include <cfenv>\n#include <cfloat>\n#include <cinttypes>\n\
    #include <ciso646>\n#include <climits>\n#include <clocale>\n#include <cmath>\n\
    #include <csetjmp>\n#include <csignal>\n#include <cstdarg>\n#include <cstdbool>\n\
    #include <cstddef>\n#include <cstdint>\n#include <cstdio>\n#include <cstdlib>\n\
    #include <cstring>\n#include <ctgmath>\n#include <ctime>\n#include <cwchar>\n\
    #include <cwctype>\n\n#line 2 \"template/macro.hpp\"\n\n#define all(v) (v).begin(),(v).end()\n\
    #define rall(v) (v).rbegin(),(v).rend()\n#define sz(v) (int((v).size()))\n#line\
    \ 5 \"template/util.hpp\"\n\ntemplate<typename T>\nvoid unq(std::vector<T> &arr)\
    \ {\n    sort(all(arr));\n    arr.erase(unique(all(arr)), arr.end());\n}\n#line\
    \ 79 \"template/template.hpp\"\n\nusing namespace std;\n\nusing ll = long long;\n\
    using ld = long double;\nusing ull = unsigned long long;\nusing uint = unsigned;\n\
    \nnamespace Quark {\n    void solve();\n};\n\nint main() { Quark::solve(); }\n\
    \n#line 3 \"verify/yosupo/Sample/many_aplusb.test.cpp\"\n\nusing namespace Quark;\n\
    \nvoid Quark::solve() {\n    int t;\n    cin >> t;\n    while (t--) {\n      \
    \  ll a, b;\n        cin >> a >> b;\n        cout << a + b << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/many_aplusb\"\n#include\
    \ \"../../../template/template.hpp\"\n\nusing namespace Quark;\n\nvoid Quark::solve()\
    \ {\n    int t;\n    cin >> t;\n    while (t--) {\n        ll a, b;\n        cin\
    \ >> a >> b;\n        cout << a + b << endl;\n    }\n}\n"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/util.hpp
  isVerificationFile: true
  path: verify/yosupo/Sample/many_aplusb.test.cpp
  requiredBy: []
  timestamp: '2022-07-12 17:31:52+03:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/Sample/many_aplusb.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/Sample/many_aplusb.test.cpp
- /verify/verify/yosupo/Sample/many_aplusb.test.cpp.html
title: verify/yosupo/Sample/many_aplusb.test.cpp
---