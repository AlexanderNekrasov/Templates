---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/vertex-cover-small-ans.hpp
    title: graph/vertex-cover-small-ans.hpp
  - icon: ':warning:'
    path: graph/vertex-cover.hpp
    title: graph/vertex-cover.hpp
  - icon: ':warning:'
    path: template/main.cpp
    title: template/main.cpp
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


    #define all(v) (v).begin(),(v).end()

    #define rall(v) (v).rbegin(),(v).rend()

    #define sz(v) (int((v).size()))

    '
  code: '#pragma once


    #define all(v) (v).begin(),(v).end()

    #define rall(v) (v).rbegin(),(v).rend()

    #define sz(v) (int((v).size()))

    '
  dependsOn: []
  isVerificationFile: false
  path: template/macro.hpp
  requiredBy:
  - graph/vertex-cover.hpp
  - graph/vertex-cover-small-ans.hpp
  - template/template.hpp
  - template/util.hpp
  - template/main.cpp
  timestamp: '2022-07-12 17:31:52+03:00'
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
