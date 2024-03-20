class w_segment_tree
{
    public:
    int idx;
    struct node
    {
        int ls, rs;
        /* val */
        /* lazy_tag */
    } tr[N];
    void push_up(int u) { /* modify val */ }
    void push_down(int u, int ln, int rn)
    {
        if(tr[u].ls == 0) tr[u].ls = ++ idx;
        if(tr[u].rs == 0) tr[u].rs = ++ idx;
        int mid = ln + rn >> 1;
        /* modify val */
        /* modify lazy_tag */
    }
    void modify(int u, int l, int r, int ln, int rn, int k)
    {
        if(l <= ln && rn <= r) {/* modify val */ /* modify lazy_tag */ return ;}
        int mid = ln + rn >> 1;
        push_down(u, ln, rn);
        if(l <= mid) modify(tr[u].ls, l, r, ln, mid, k);
        if(r > mid) modify(tr[u].rs, l, r, mid + 1, r, k);
        push_up(u);
    }
    /* query */
}
