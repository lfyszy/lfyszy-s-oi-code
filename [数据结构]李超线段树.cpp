class lichao_segment
{
    pubilc:
    const int N = /* max_num */;
    const double eps = 1e-9;
    int cmp(double x, double y) {return x - y > eps ? 1 : y - x > eps ? -1 : 0;}
    struct line {double k, b;} p[N << 2];
    int exc[N << 2], cnt;
    #define k(u) p[u].k
    #define b(u) p[u].b
    #define l(u) u << 1
    #define r(u) u << 1 | 1
    double calc(int id, int d) {return k(id) * d + b(id);}
    void add(int x0, int y0, int x1, int y1)
    {
        cnt ++;
        if(x0 == x1) k(cnt) = 0, b(cnt) = max(y0, y1);
        else k(cnt) = 1.0 * (y1 - y0) / (x1 - x0), b(cnt) = y0 - k(cnt) * x0;
    }
    void modify(int u, int ln, int rn, int k)
    {
        int &v = exc[u], mid = ln + rn >> 1;
        int cmid = cmp(calc(k, mid), calc(v, mid));
        if(cmid == 1 || (!cmid && k < v)) swap(k, v);
        int cl = cmp(calc(k, ln), calc(v, ln)), cr = cmp(calc(k, rn), calc(v, rn));
        if(cl == 1 || (!cl && k < v)) modify(l(u), ln, mid, k);
        if(cr == 1 || (!cr && k < v)) modify(r(u), mid + 1, rn, k);
    }
    void update(int u, int l, int r, int ln, int rn, int k)
    {
        if(l <= ln && rn <= r) return modify(u, ln, rn, k);
        int mid = ln + rn >> 1;
        if(l <= mid) update(l(u), l, r, ln, mid, k);
        if(mid < r) update(r(u), l, r, mid + 1, rn, k);
    }
    PDI pmax(PDI x, PDI y)
    {
        if(cmp(x.fst, y.fst) == 1) return x;
        else if(cmp(x.fst, y.fst) == -1) return y;
        else return x.scd < y.scd ? x : y;
    }
    PDI query(int u, int l, int r, int d)
    {
        if(r < d || d < l) return {0, 0};
        int mid = l + r >> 1;
        double res = calc(exc[u], d);
        if(l == r) return {res, exc[u]};
        else return pmax({res, exc[u]}, pmax(query(l(u), l, mid, d), query(r(u), mid + 1, r, d)));
    }
};