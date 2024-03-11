class segment_tree
{
    public:
    struct node
    {
        int l, r;
        // val
        // lazy_tag
    } tr[N << 2];
    #define l(x) x << 1
    #define r(x) x << 1 | 1
    void push_up(int u) {/* modify val */}
    void push_down(int u)
    {
        //modify sons' val
        //modify sons' lazy_tag
    }
    void build(int u, int l, int r, int a[])
    {
        tr[u] = {l, r, /* val */, /* lazy_tag */};
        if(l == r) {/* leaf */ return ;}
        int mid = l + r >> 1;
        build(l(u), l, mid, a), build(r(u), mid + 1, r, a), push_up(u);
    }
    void modify(int u, int l, int r, int k)
    {
        if(l <= tr[u].l && tr[u].r <= r)
        {
            //modify val
            //modify lazy_tag
            return ;
        }
        push_down(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if(l <= mid) modify(l(u), l, r, k);
        if(r > mid) modify(r(u), l, r, k);
        push_up(u);
    }
    int query(int u, int l ,int r)
    {
        if(l <= tr[u].l && tr[u].r <= r) return /* val */;
        push_down(u);
        int mid = tr[u].l + tr[u].r >> 1, res = 0;
        if(l <= mid) res = (res /* opt */ query(l(u), l, r)) % m;
        if(r > mid) res = (res /* opt */ query(r(u), l, r)) % m;
        return res;
    }
} ;