class  kruskal_tree
{
    public:
    const int N = /* max_edge_num */, M = /* 2_times_max_point_num */;
    struct edge
    {
        int l, r, w;
        bool operator<(const edge& t)const {return w > t.w;}
    } ed[N];
    int val[M], cnt;
    vector<int> e[M];
    int f[M][30], dfn[M], idx;
    int fa[M]; bool st[M];
    int get(int u, int v) {return dfn[u] < dfn[v] ? u : v;}
    void dfs(int u, int fath)
    {
        f[dfn[u] = ++ idx][0] = fath, st[u] = 1;
        for(auto v : e[u]) if(v != fath) dfs(v, u);
    }
    void init(int n)
    {
        for(int i = 1; i <= __lg(n); i ++)
            for(int j = 1; j + (1 << i) - 1 <= n; j ++)
                f[j][i] = get(f[j][i - 1], f[j + (1 << i - 1)][i - 1]);
    }
    int lca(int u, int v)
    {
        if(u == v) return u;
        if((u = dfn[u]) > (v = dfn[v])) swap(u, v);
        int d = __lg(v - u ++);
        return get(f[u][d], f[v - (1 << d) + 1][d]);
    }
    int find(int x) {return fa[x] != x ? fa[x] = find(fa[x]) : x;}
    void kruskal(int n, int m)
    {
        sort(ed + 1, ed + m + 1);
        for(int i = 1; i <= n; i ++) fa[i] = i;
        for(int i = 1; i <= m; i ++)
        {
            int fl = find(ed[i].l), fr = find(ed[i].r);
            if(fl != fr)
            {
                val[++ cnt] = ed[i].w;
                fa[cnt] = fa[fl] = fa[fr] = cnt;
                e[fl].push_back(cnt); e[cnt].push_back(fl);
                e[fr].push_back(cnt); e[cnt].push_back(fr);
            }
        }
        for(int i = 1; i <= cnt; i ++) if(!st[find(i)]) dfs(find(i), 0);
        init(cnt);
    }
} ;