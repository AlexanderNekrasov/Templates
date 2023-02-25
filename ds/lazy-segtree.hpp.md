---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/lazy-segtree.hpp\"\n\n// LazySegmentTree\ntemplate <typename\
    \ T, typename E, typename F, typename G, typename H>\nstruct LazySegmentTree {\n\
    \    int n, height;\n    F f;\n    G g;\n    H h;\n    T ti;\n    E ei;\n    vector<T>\
    \ tree;\n    vector<E> mod;\n    LazySegmentTree(int _n, F _f, G _g, H _h, T _ti,\
    \ E _ei)\n        : f(_f), g(_g), h(_h), ti(_ti), ei(_ei) {\n            init(_n);\n\
    \        }\n    LazySegmentTree(const vector<T> &v, F _f, G _g, H _h, T _ti, E\
    \ _ei)\n        : f(_f), g(_g), h(_h), ti(_ti), ei(_ei) {\n            init((int)v.size());\n\
    \            build(v);\n        }\n    void init(int _n) {\n        n = 1;\n \
    \       height = 0;\n        while (n < _n) n <<= 1, height++;\n        tree.assign(2\
    \ * n, ti);\n        mod.assign(2 * n, ei);\n    }\n    void build(const vector<T>\
    \ &v) {\n        int _n = v.size();\n        init(_n);\n        for (int i = 0;\
    \ i < _n; i++) tree[n + i] = v[i];\n        for (int i = n - 1; i; i--)\n    \
    \        tree[i] = f(tree[(i << 1) | 0], tree[(i << 1) | 1]);\n    }\n    inline\
    \ T reflect(int k) { return mod[k] == ei ? tree[k] : g(tree[k], mod[k]); }\n \
    \   inline void eval(int k) {\n        if (mod[k] == ei) return;\n        mod[(k\
    \ << 1) | 0] = h(mod[(k << 1) | 0], mod[k]);\n        mod[(k << 1) | 1] = h(mod[(k\
    \ << 1) | 1], mod[k]);\n        tree[k] = reflect(k);\n        mod[k] = ei;\n\
    \    }\n    inline void thrust(int k) {\n        for (int i = height; i; i--)\
    \ eval(k >> i);\n    }\n    inline void recalc(int k) {\n        while (k >>=\
    \ 1) tree[k] = f(reflect((k << 1) | 0), reflect((k << 1) | 1));\n    }\n    void\
    \ update(int a, int b, E x) {\n        if (a >= b) return;\n        thrust(a +=\
    \ n);\n        thrust(b += n - 1);\n        for (int l = a, r = b + 1; l < r;\
    \ l >>= 1, r >>= 1) {\n            if (l & 1) mod[l] = h(mod[l], x), l++;\n  \
    \          if (r & 1) --r, mod[r] = h(mod[r], x);\n        }\n        recalc(a);\n\
    \        recalc(b);\n    }\n    void set_val(int a, T x) {\n        thrust(a +=\
    \ n);\n        tree[a] = x;\n        mod[a] = ei;\n        recalc(a);\n    }\n\
    \    T get_val(int a) {\n        thrust(a += n);\n        return reflect(a);\n\
    \    }\n    T get(int a, int b) {\n        if (a >= b) return ti;\n        thrust(a\
    \ += n);\n        thrust(b += n - 1);\n        T vl = ti, vr = ti;\n        for\
    \ (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) vl\
    \ = f(vl, reflect(l++));\n            if (r & 1) vr = f(reflect(--r), vr);\n \
    \       }\n        return f(vl, vr);\n    }\n};\n"
  code: "#pragma once\n\n// LazySegmentTree\ntemplate <typename T, typename E, typename\
    \ F, typename G, typename H>\nstruct LazySegmentTree {\n    int n, height;\n \
    \   F f;\n    G g;\n    H h;\n    T ti;\n    E ei;\n    vector<T> tree;\n    vector<E>\
    \ mod;\n    LazySegmentTree(int _n, F _f, G _g, H _h, T _ti, E _ei)\n        :\
    \ f(_f), g(_g), h(_h), ti(_ti), ei(_ei) {\n            init(_n);\n        }\n\
    \    LazySegmentTree(const vector<T> &v, F _f, G _g, H _h, T _ti, E _ei)\n   \
    \     : f(_f), g(_g), h(_h), ti(_ti), ei(_ei) {\n            init((int)v.size());\n\
    \            build(v);\n        }\n    void init(int _n) {\n        n = 1;\n \
    \       height = 0;\n        while (n < _n) n <<= 1, height++;\n        tree.assign(2\
    \ * n, ti);\n        mod.assign(2 * n, ei);\n    }\n    void build(const vector<T>\
    \ &v) {\n        int _n = v.size();\n        init(_n);\n        for (int i = 0;\
    \ i < _n; i++) tree[n + i] = v[i];\n        for (int i = n - 1; i; i--)\n    \
    \        tree[i] = f(tree[(i << 1) | 0], tree[(i << 1) | 1]);\n    }\n    inline\
    \ T reflect(int k) { return mod[k] == ei ? tree[k] : g(tree[k], mod[k]); }\n \
    \   inline void eval(int k) {\n        if (mod[k] == ei) return;\n        mod[(k\
    \ << 1) | 0] = h(mod[(k << 1) | 0], mod[k]);\n        mod[(k << 1) | 1] = h(mod[(k\
    \ << 1) | 1], mod[k]);\n        tree[k] = reflect(k);\n        mod[k] = ei;\n\
    \    }\n    inline void thrust(int k) {\n        for (int i = height; i; i--)\
    \ eval(k >> i);\n    }\n    inline void recalc(int k) {\n        while (k >>=\
    \ 1) tree[k] = f(reflect((k << 1) | 0), reflect((k << 1) | 1));\n    }\n    void\
    \ update(int a, int b, E x) {\n        if (a >= b) return;\n        thrust(a +=\
    \ n);\n        thrust(b += n - 1);\n        for (int l = a, r = b + 1; l < r;\
    \ l >>= 1, r >>= 1) {\n            if (l & 1) mod[l] = h(mod[l], x), l++;\n  \
    \          if (r & 1) --r, mod[r] = h(mod[r], x);\n        }\n        recalc(a);\n\
    \        recalc(b);\n    }\n    void set_val(int a, T x) {\n        thrust(a +=\
    \ n);\n        tree[a] = x;\n        mod[a] = ei;\n        recalc(a);\n    }\n\
    \    T get_val(int a) {\n        thrust(a += n);\n        return reflect(a);\n\
    \    }\n    T get(int a, int b) {\n        if (a >= b) return ti;\n        thrust(a\
    \ += n);\n        thrust(b += n - 1);\n        T vl = ti, vr = ti;\n        for\
    \ (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) vl\
    \ = f(vl, reflect(l++));\n            if (r & 1) vr = f(reflect(--r), vr);\n \
    \       }\n        return f(vl, vr);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/lazy-segtree.hpp
  requiredBy: []
  timestamp: '2023-02-25 13:28:05+03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/lazy-segtree.hpp
layout: document
redirect_from:
- /library/ds/lazy-segtree.hpp
- /library/ds/lazy-segtree.hpp.html
title: ds/lazy-segtree.hpp
---
