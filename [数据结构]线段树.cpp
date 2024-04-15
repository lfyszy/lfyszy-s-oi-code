class segment_tree
{
    const int N = /* max_num */;
    public:
    struct node
    {
        // val
        // lazy_tag
    } tr[N << 2];
    #define l(x) x << 1
    #define r(x) x << 1 | 1
    void push_up(int u) {/* modify val */}
    void push_down(int u, int ln, int rn)
    {
        //modify sons' val
        //modify sons' lazy_tag
    }
    void build(int u, int l, int r, int a[])
    {
        tr[u] = {/* val */, /* lazy_tag */};
        if(l == r) {/* leaf */ return ;}
        int mid = l + r >> 1;
        build(l(u), l, mid, a), build(r(u), mid + 1, r, a), push_up(u);
    }
    void modify(int u, int l, int r, int ln, int rn, int k)
    {
        if(l <= ln && rn <= r)
        {
            //modify val
            //modify lazy_tag
            return ;
        }
        push_down(u, ln, rn);
        int mid = ln + rn >> 1;
        if(l <= mid) modify(l(u), l, r, ln, mid, k);
        if(r > mid) modify(r(u), l, r, mid + 1, rn, k);
        push_up(u);
    }
    int query(int u, int l ,int r, int ln, int rn)
    {
        if(l <= ln && rn <= r) return /* val */;
        push_down(u, ln, rn);
        int mid = ln + rn >> 1, res = 0;
        if(l <= mid) res = res /* opt */ query(l(u), l, r, ln, mid);
        if(r > mid) res = res /* opt */ query(r(u), l, r, mid + 1, rn);
        return res;
    }
} ;
