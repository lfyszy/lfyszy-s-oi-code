const int N = /*max num*/;
bool st[N];
int phi[N];
vector<int> p;
void getprime(int n)
{
    phi[1] = 1;
    for(int i = 2; i <= n; i ++)
    {
        if(!st[i]) p.push_back(i), phi[i] = i - 1;
        for(auto v : p)
        {
            if(v * i > n) break;
            st[v * i] = 1;
            if(i % v == 0) {phi[i * v] = phi[i] * v; break;}
            else phi[i * v] = phi[i] * (v - 1);
        }
    }
}
int qmul(int a, int b, int p) {return (a * b - (int)((long double) a / p * b) * p + p) % p;}
int qpow(int a, int b, int p) {int res = 1; while(b) {if(b & 1) res = qmul(res, a, p); a = qmul(a, a, p); b >>= 1;} return res;}
struct prime {int val, cnt;};
vector<prime> dip;
void divide(int n)
{
    dip.clear();
    for(int i = 2;i <= n / i; i ++)
        if(n % i == 0)
        {
            int s = 0;
            while(n % i == 0)
                n /= i, s ++;
            dip.push_back({i, s});
        }
    if(n > 1) dip.push_back({n, 1});
}
bool exist(int n)
{
    if(n == 2 || n == 4) return true;
    if(n % 2 == 0) n /= 2;
    for(auto i : p)
        if(n % i == 0)
        {
            if(i == 2) return false;
            while(n % i == 0) n /= i;
            return n == 1;
        }
    return false;
}
bool check_rt(int g, int n)
{
    if(__gcd(g, n) != 1) return 0;
    for(auto i : dip) if(qpow(g, phi[n] / i.val, n) == 1) return false;
    return true;
}
vector<int> getrt()
{
    int n, d; cin >> n >> d;
    getprime(n);
    if(!exist(n)) {cout << "0\n\n"; return ;}
    divide(phi[n]);
    int g = 0; while(!check_rt(++ g, n));
    vector<int> ans;
    for(int i = 1, pw = 1; ans.size() < phi[phi[n]]; i ++)
    {
        pw = pw * g % n;
        if(__gcd(phi[n], i) == 1) ans.push_back(pw);
    }
    sort(ans.begin(), ans.end());
    return ans;
}