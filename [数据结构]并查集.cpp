class UFset
{
    public:
    const int N = /* max_num */;
    int fa[N];
    void init(int n) {for(int i = 1; i <= n; i ++) fa[i] = i;}
    int find(int x) {return fa[x] != x ? fa[x] = find(fa[x]) : x;}
} ;