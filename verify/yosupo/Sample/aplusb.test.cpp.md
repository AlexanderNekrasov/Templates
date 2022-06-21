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
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/yosupo/Sample/aplusb.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n#line 2 \"template/macro.hpp\"\n\
    \n#include <bits/stdc++.h>\n\n#define all(v) (v).begin(),(v).end()\n#define rall(v)\
    \ (v).rbegin(),(v).rend()\n#define sz(v) (int((v).size()))\n#line 5 \"template/util.hpp\"\
    \n\ntemplate<typename T>\nvoid unq(std::vector<T> &arr) {\n    sort(all(arr));\n\
    \    arr.erase(unique(all(arr)), arr.end());\n}\n#line 4 \"template/template.hpp\"\
    \n\n#line 6 \"template/template.hpp\"\nusing namespace std;\n\ntypedef long long\
    \ ll;\ntypedef long double ldb;\n\nnamespace Quark {\n    void solve();\n};\n\n\
    int main() { Quark::solve(); }\n\n#line 3 \"verify/yosupo/Sample/aplusb.test.cpp\"\
    \n\nusing namespace Quark;\n\nvoid Quark::solve() {\n    int a, b;\n    cin >>\
    \ a >> b;\n    cout << a + b << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../../template/template.hpp\"\
    \n\nusing namespace Quark;\n\nvoid Quark::solve() {\n    int a, b;\n    cin >>\
    \ a >> b;\n    cout << a + b << endl;\n}\n"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/util.hpp
  isVerificationFile: true
  path: verify/yosupo/Sample/aplusb.test.cpp
  requiredBy: []
  timestamp: '2022-06-21 08:42:58+03:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/Sample/aplusb.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/Sample/aplusb.test.cpp
- /verify/verify/yosupo/Sample/aplusb.test.cpp.html
title: verify/yosupo/Sample/aplusb.test.cpp
---
