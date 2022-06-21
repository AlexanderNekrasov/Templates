---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/macro.hpp
    title: template/macro.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/Sample/aplusb.test.cpp
    title: verify/yosupo/Sample/aplusb.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/Sample/many_aplusb.test.cpp
    title: verify/yosupo/Sample/many_aplusb.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/macro.hpp\"\n\n#include <bits/stdc++.h>\n\n#define\
    \ all(v) (v).begin(),(v).end()\n#define rall(v) (v).rbegin(),(v).rend()\n#define\
    \ sz(v) (int((v).size()))\n#line 5 \"template/util.hpp\"\n\ntemplate<typename\
    \ T>\nvoid unq(std::vector<T> &arr) {\n    sort(all(arr));\n    arr.erase(unique(all(arr)),\
    \ arr.end());\n}\n"
  code: "#pragma once\n#include \"macro.hpp\"\n#include <vector>\n#include <algorithm>\n\
    \ntemplate<typename T>\nvoid unq(std::vector<T> &arr) {\n    sort(all(arr));\n\
    \    arr.erase(unique(all(arr)), arr.end());\n}\n"
  dependsOn:
  - template/macro.hpp
  isVerificationFile: false
  path: template/util.hpp
  requiredBy:
  - template/template.hpp
  timestamp: '2022-06-21 08:42:58+03:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/Sample/many_aplusb.test.cpp
  - verify/yosupo/Sample/aplusb.test.cpp
documentation_of: template/util.hpp
layout: document
redirect_from:
- /library/template/util.hpp
- /library/template/util.hpp.html
title: template/util.hpp
---
