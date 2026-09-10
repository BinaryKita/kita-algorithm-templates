struct DSU {
    vector<int> fa;
    DSU(int n) : fa(n + 1) {
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int x) {
        while (x != fa[x]) {
            x = fa[x] = fa[fa[x]];
        }
        return x;
    }
    bool merge(int x, int y) { // 设x是y的祖先
        x = find(x), y = find(y);
        if (x == y) return false;
        fa[y] = x;
        return true;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
};
struct Tree {
    using TII = tuple<i64, int, int>;
    int n;
    priority_queue<TII, vector<TII>, greater<TII>> ver;

    Tree(int n) {
        this->n = n;
    }
    void add(int x, int y, i64 w) {
        ver.emplace(w, x, y); // 注意顺序
    }
    i64 kruskal() {
        DSU dsu(n);
        i64 ans = 0;
        int cnt = 0;
        while (ver.size()) {
            auto [w, x, y] = ver.top();
            ver.pop();
            if (dsu.same(x, y)) continue;
            dsu.merge(x, y);
            ans += w;
            cnt++;
        }
        if(cnt < n - 1) return -1;
        return ans;
    }
};
