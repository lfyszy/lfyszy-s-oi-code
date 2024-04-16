class LCT_son
{
    public:
    const int N = 1e5 + 10;
    struct node {int ch[2], fa; int tot, siz;/* 子树、虚子树大小 */int lazy_rev;} tr[N];
    int getch(int u) {return tr[tr[u].fa].ch[1] == u;}
    void push_up(int u) {tr[u].tot = tr[tr[u].ch[0]].tot + tr[tr[u].ch[1]].tot + tr[u].siz + 1;}
    void push_down(int u)
    {
        if(tr[u].lazy_rev)
        {
            int p;
            if(p = tr[u].ch[0]) swap(tr[p].ch[0], tr[p].ch[1]), tr[p].lazy_rev ^= 1;
            if(p = tr[u].ch[1]) swap(tr[p].ch[0], tr[p].ch[1]), tr[p].lazy_rev ^= 1;
        } tr[u].lazy_rev = 0;
    }
    bool isroot(int u) {return tr[tr[u].fa].ch[0] != u && tr[tr[u].fa].ch[1] != u;}
    void update(int u) {if(!isroot(u)) update(tr[u].fa); push_down(u);}
    void rotate(int x)
    {
        int y = tr[x].fa, z = tr[y].fa, k = getch(x);
        if(!isroot(y)) tr[z].ch[getch(y)] = x; tr[x].fa = z;
        tr[y].ch[k] = tr[x].ch[k ^ 1], tr[tr[y].ch[k]].fa = y;
        tr[x].ch[k ^ 1] = y, tr[y].fa = x; push_up(x), push_up(y);
    }
    void splay(int u)
    {
        update(u);
        while(!isroot(u)) {if(!isroot(tr[u].fa)) rotate(getch(u) ^ getch(tr[u].fa) ? u : tr[u].fa); rotate(u);}
        push_up(u);
    }
    void access(int u) {for(int p = 0; u; u = tr[p = u].fa) splay(u), tr[u].siz += tr[tr[u].ch[1]].tot - tr[p].tot, tr[u].ch[1] = p, push_up(u);}
    void makeroot(int u) {access(u), splay(u), swap(tr[u].ch[0], tr[u].ch[1]), tr[u].lazy_rev ^= 1;}
    int split(int u, int v) {makeroot(u), access(v), splay(v); return v;}
    int findroot(int u)
    {
        access(u), splay(u), push_down(u);
        while(tr[u].ch[0]) u = tr[u].ch[0], push_down(u); splay(u);
        return u;
    }
    void link(int u, int v) {split(u, v); tr[v].siz += tr[u].tot; tr[u].fa = v; splay(v);}
    void cut(int u, int v) {split(u, v); tr[u].fa = tr[v].ch[0] = 0; splay(v);}
} ;