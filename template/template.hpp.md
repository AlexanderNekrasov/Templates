---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':heavy_check_mark:'
    path: template/util.hpp
    title: template/util.hpp
  _extendedRequiredBy: []
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
    \ arr.end());\n}\n#line 4 \"template/template.hpp\"\n\n#line 6 \"template/template.hpp\"\
    \nusing namespace std;\n\ntypedef long long ll;\ntypedef long double ldb;\n\n\
    namespace Quark {\n    void solve();\n};\n\nint main() { Quark::solve(); }\n\n"
  code: "#pragma once\n#include \"macro.hpp\"\n#include \"util.hpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntypedef long long ll;\ntypedef long double ldb;\n\nnamespace\
    \ Quark {\n    void solve();\n};\n\nint main() { Quark::solve(); }\n\n"
  dependsOn:
  - template/macro.hpp
  - template/util.hpp
  isVerificationFile: false
  path: template/template.hpp
  requiredBy: []
  timestamp: '2022-06-21 08:42:58+03:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/Sample/many_aplusb.test.cpp
  - verify/yosupo/Sample/aplusb.test.cpp
documentation_of: template/template.hpp
layout: document
redirect_from:
- /library/template/template.hpp
- /library/template/template.hpp.html
title: template/template.hpp
---
