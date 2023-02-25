#pragma once

// LazySegmentTree
template <typename T, typename E, typename F, typename G, typename H>
struct LazySegmentTree {
    int n, height;
    F f;
    G g;
    H h;
    T ti;
    E ei;
    vector<T> tree;
    vector<E> mod;
    LazySegmentTree(int _n, F _f, G _g, H _h, T _ti, E _ei)
        : f(_f), g(_g), h(_h), ti(_ti), ei(_ei) {
            init(_n);
        }
    LazySegmentTree(const vector<T> &v, F _f, G _g, H _h, T _ti, E _ei)
        : f(_f), g(_g), h(_h), ti(_ti), ei(_ei) {
            init((int)v.size());
            build(v);
        }
    void init(int _n) {
        n = 1;
        height = 0;
        while (n < _n) n <<= 1, height++;
        tree.assign(2 * n, ti);
        mod.assign(2 * n, ei);
    }
    void build(const vector<T> &v) {
        int _n = v.size();
        init(_n);
        for (int i = 0; i < _n; i++) tree[n + i] = v[i];
        for (int i = n - 1; i; i--)
            tree[i] = f(tree[(i << 1) | 0], tree[(i << 1) | 1]);
    }
    inline T reflect(int k) { return mod[k] == ei ? tree[k] : g(tree[k], mod[k]); }
    inline void eval(int k) {
        if (mod[k] == ei) return;
        mod[(k << 1) | 0] = h(mod[(k << 1) | 0], mod[k]);
        mod[(k << 1) | 1] = h(mod[(k << 1) | 1], mod[k]);
        tree[k] = reflect(k);
        mod[k] = ei;
    }
    inline void thrust(int k) {
        for (int i = height; i; i--) eval(k >> i);
    }
    inline void recalc(int k) {
        while (k >>= 1) tree[k] = f(reflect((k << 1) | 0), reflect((k << 1) | 1));
    }
    void update(int a, int b, E x) {
        if (a >= b) return;
        thrust(a += n);
        thrust(b += n - 1);
        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) mod[l] = h(mod[l], x), l++;
            if (r & 1) --r, mod[r] = h(mod[r], x);
        }
        recalc(a);
        recalc(b);
    }
    void set_val(int a, T x) {
        thrust(a += n);
        tree[a] = x;
        mod[a] = ei;
        recalc(a);
    }
    T get_val(int a) {
        thrust(a += n);
        return reflect(a);
    }
    T get(int a, int b) {
        if (a >= b) return ti;
        thrust(a += n);
        thrust(b += n - 1);
        T vl = ti, vr = ti;
        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) vl = f(vl, reflect(l++));
            if (r & 1) vr = f(reflect(--r), vr);
        }
        return f(vl, vr);
    }
};
