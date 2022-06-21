---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':heavy_check_mark:'
    path: template/util.hpp
    title: template/util.hpp
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
  bundledCode: '#line 2 "template/macro.hpp"


    #include <bits/stdc++.h>


    #define all(v) (v).begin(),(v).end()

    #define rall(v) (v).rbegin(),(v).rend()

    #define sz(v) (int((v).size()))

    '
  code: '#pragma once


    #include <bits/stdc++.h>


    #define all(v) (v).begin(),(v).end()

    #define rall(v) (v).rbegin(),(v).rend()

    #define sz(v) (int((v).size()))

    '
  dependsOn: []
  isVerificationFile: false
  path: template/macro.hpp
  requiredBy:
  - template/template.hpp
  - template/util.hpp
  timestamp: '2022-06-21 08:42:58+03:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/Sample/many_aplusb.test.cpp
  - verify/yosupo/Sample/aplusb.test.cpp
documentation_of: template/macro.hpp
layout: document
redirect_from:
- /library/template/macro.hpp
- /library/template/macro.hpp.html
title: template/macro.hpp
---
