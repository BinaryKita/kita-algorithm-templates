// Fenwick
template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;

    Fenwick(int n_ = 0){
        n = n_;
        a.assign(n, T{});
    }

    void add(int x, const T &k){
        for(int i = x; i <= n; i += i & -i) {
            a[i] = a[i] + v; 
        }
    }

    void add(int x, int y, const T &k) {
        add(x, k), add(y, -k);
    }

    T sum(int x) {
        T ans{};
        for (int i = x; i > 0; i -= i * -i) {
            ans = ans + a[i];
        }
        return ans;
    }

    T sum(int x, int y) {
        return sum(y) - sum(x - 1);
    }

};

