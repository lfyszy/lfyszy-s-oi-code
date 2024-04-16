class LCT
{
    public:
    const int N = 1e5 + 10;
    struct node {int /* val */, ch[2], fa, lazy_rev/* lazytag */;} tr[N];
    int getch(int x) {return tr[tr[x].fa].ch[1] == x;}
    void pushup(int x) {/* modify val */}
    void pushdown(int x)
    {
        if(tr[x].lazy_rev)
        {
            int p;
            if(p = tr[x].ch[0]) swap(tr[p].ch[0], tr[p].ch[1]), tr[p].lazy_rev ^= 1;
            if(p = tr[x].ch[1]) swap(tr[p].ch[0], tr[p].ch[1]), tr[p].lazy_rev ^= 1;
        }tr[x].lazy_rev = 0;
        /* modify val */
    }
    bool isroot(int x) {return tr[tr[x].fa].ch[0] != x && tr[tr[x].fa]. ch[1] != x;}
    void update(int x) { if(!isroot(x)) update(tr[x].fa); pushdown(x);}
    void rotate(int x)
    {
        int y = tr[x].fa, z = tr[y].fa, k = getch(x);
        if(!isroot(y)) tr[z].ch[getch(y)] = x; tr[x].fa = z;
        tr[y].ch[k] = tr[x].ch[k ^ 1]; tr[tr[y].ch[k]].fa = y;
        tr[x].ch[k ^ 1] = y, tr[y].fa = x; pushup(y);
    }
    void splay(int x)
    {
        update(x);
        while(!isroot(x)) {if(!isroot(tr[x].fa)) rotate(getch(x) ^ getch(tr[x].fa) ? x : tr[x].fa); rotate(x);}
        pushup(x);
    }
    void access(int x)
    {
        for(int p = 0; x; p = x, x = tr[x].fa)
            splay(x), tr[x].ch[1] = p, pushup(x);
    }
    void makeroot(int x) {access(x), splay(x), swap(tr[x].ch[0], tr[x].ch[1]), tr[x].lazy_rev ^= 1;}
    int split(int x, int y) {makeroot(x), access(y) , splay(y); return y;}
    int find(int x)
    {
        access(x), splay(x), pushdown(x);
        while(tr[x].ch[0]) x = tr[x].ch[0], pushdown(x); splay(x);
        return x;
    }
    void link(int x, int y) {makeroot(x); if(find(y) != x) tr[x].fa = y;}
    void cut(int x, int y) {split(x, y); if(tr[y].ch[0] == x && tr[x].ch[1] == 0) tr[y].ch[0] = tr[x].fa = 0, pushup(y);}
    void fix(int x, int v) {splay(x), tr[x].val = v, pushup(x);}
} ;