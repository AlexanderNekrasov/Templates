---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: modint/modint-arbitrary.hpp
    title: modint/modint-arbitrary.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"modint/barrett-reduction.hpp\"\n\n#include <utility>\nusing\
    \ namespace std;\n\nstruct Barrett {\n  using u32 = unsigned int;\n  using i64\
    \ = long long;\n  using u64 = unsigned long long;\n  u32 m;\n  u64 im;\n  Barrett()\
    \ : m(), im() {}\n  Barrett(int n) : m(n), im(u64(-1) / m + 1) {}\n  constexpr\
    \ inline i64 quo(u64 n) {\n    u64 x = u64((__uint128_t(n) * im) >> 64);\n   \
    \ u32 r = n - x * m;\n    return m <= r ? x - 1 : x;\n  }\n  constexpr inline\
    \ i64 rem(u64 n) {\n    u64 x = u64((__uint128_t(n) * im) >> 64);\n    u32 r =\
    \ n - x * m;\n    return m <= r ? r + m : r;\n  }\n  constexpr inline pair<i64,\
    \ int> quorem(u64 n) {\n    u64 x = u64((__uint128_t(n) * im) >> 64);\n    u32\
    \ r = n - x * m;\n    if (m <= r) return {x - 1, r + m};\n    return {x, r};\n\
    \  }\n  constexpr inline i64 pow(u64 n, i64 p) {\n    u32 a = rem(n), r = m ==\
    \ 1 ? 0 : 1;\n    while (p) {\n      if (p & 1) r = rem(u64(r) * a);\n      a\
    \ = rem(u64(a) * a);\n      p >>= 1;\n    }\n    return r;\n  }\n};\n"
  code: "#pragma once\n\n#include <utility>\nusing namespace std;\n\nstruct Barrett\
    \ {\n  using u32 = unsigned int;\n  using i64 = long long;\n  using u64 = unsigned\
    \ long long;\n  u32 m;\n  u64 im;\n  Barrett() : m(), im() {}\n  Barrett(int n)\
    \ : m(n), im(u64(-1) / m + 1) {}\n  constexpr inline i64 quo(u64 n) {\n    u64\
    \ x = u64((__uint128_t(n) * im) >> 64);\n    u32 r = n - x * m;\n    return m\
    \ <= r ? x - 1 : x;\n  }\n  constexpr inline i64 rem(u64 n) {\n    u64 x = u64((__uint128_t(n)\
    \ * im) >> 64);\n    u32 r = n - x * m;\n    return m <= r ? r + m : r;\n  }\n\
    \  constexpr inline pair<i64, int> quorem(u64 n) {\n    u64 x = u64((__uint128_t(n)\
    \ * im) >> 64);\n    u32 r = n - x * m;\n    if (m <= r) return {x - 1, r + m};\n\
    \    return {x, r};\n  }\n  constexpr inline i64 pow(u64 n, i64 p) {\n    u32\
    \ a = rem(n), r = m == 1 ? 0 : 1;\n    while (p) {\n      if (p & 1) r = rem(u64(r)\
    \ * a);\n      a = rem(u64(a) * a);\n      p >>= 1;\n    }\n    return r;\n  }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: modint/barrett-reduction.hpp
  requiredBy:
  - modint/modint-arbitrary.hpp
  timestamp: '2023-02-25 13:28:05+03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: modint/barrett-reduction.hpp
layout: document
redirect_from:
- /library/modint/barrett-reduction.hpp
- /library/modint/barrett-reduction.hpp.html
title: modint/barrett-reduction.hpp
---
