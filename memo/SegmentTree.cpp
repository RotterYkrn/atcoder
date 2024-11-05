template<class T, const T& (* const op)(const T &, const T &) = max, const T e = T()>
struct SegTree {
    vector<T> tree, lazy;
    size_t n;
    const T LAZY_DEF = numeric_limits<T>::max();

    SegTree(const size_t N) noexcept {
        size_t tree_size = 2;
        while (tree_size < N) {
            tree_size *= 2;
        }
        tree = vector<T>(tree_size * 2, e);
        lazy = vector<T>(tree_size * 2, LAZY_DEF);
        n = tree_size;
    }

    SegTree(const vector<T> v) noexcept : SegTree(v.size()) {
        copy(v.begin(), v.end(), tree.begin() + n - 1);
        for (size_t i = n - 2; i >= 0; i--) {
            tree[i] = op(tree[i * 2 + 1], tree[i * 2 + 2]);
        }
    }

    inline void delayed_evaluation(size_t node) noexcept {
        if (lazy[node] == LAZY_DEF) {
            return;
        }
        if (node < n - 1) {
            lazy[node * 2 + 1] = lazy[node];
            lazy[node * 2 + 2] = lazy[node];
        }
        tree[node] = lazy[node];
        lazy[node] = LAZY_DEF;
    }

    void set(const size_t sl, const size_t sr, const T v, const size_t node, const size_t nl, const size_t nr) noexcept {
        delayed_evaluation(node);
        if (sl <= nl && nr <= sr) {
            lazy[node] = v;
            delayed_evaluation(node);
        } else if (sl < nr && nl < sr) {
            set(sl, sr, v, node * 2 + 1, nl, (nl + nr) / 2);
            set(sl, sr, v, node * 2 + 2, (nl + nr) / 2, nr);
            tree[node] = op(tree[node * 2 + 1], tree[node * 2 + 2]);
        }
    }
    inline void set(const size_t l, const size_t r, const T value) noexcept {
        set(l, r, value, 0, 0, n);
    }
    inline void set(const size_t p, const T value) noexcept {
        set(p, p + 1, value);
    }

    T query_sub(const size_t ql, const size_t qr, const size_t node, const size_t nl, const size_t nr) noexcept {
        delayed_evaluation(node);
        if (nr <= ql || qr <= nl) {
            return e;
        } else if (ql <= nl && nr <= qr) {
            return tree[node];
        } else {
            T vl = query_sub(ql, qr, node * 2 + 1, nl, (nl + nr) / 2);
            T vr = query_sub(ql, qr, node * 2 + 2, (nl + nr) / 2, nr);
            return op(vl, vr);
        }
    }
    // [l, r)
    inline T query(const size_t l, const size_t r) noexcept {
        return query_sub(l, r, 0, 0, n);
    }

    inline T query_all() noexcept {
        return tree[0];
    }
};
