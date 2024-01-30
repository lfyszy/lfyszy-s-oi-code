int qmul(int a, int b, int p) {return (a * b - (int)((long double) a / p * b) * p + p) % p;}
int qpow(int a, int b, int p) {int res = 1; while(b) {if(b & 1) res = qmul(res, a, p); a = qmul(a, a, p); b >>= 1;} return res;}
struct complexnum {int re, im;};
complexnum cmul(complexnum a, complexnum b, int p, int ii) {return {(a.re * b.re % p + a.im * b.im % p * ii % p) % p, (a.re * b.im % p + b.re * a.im % p) % p};}
complexnum qpow(complexnum a, int b, int p, int ii) {complexnum res = {1, 0}; while(b) {if(b & 1) res = cmul(res, a, p, ii); a = cmul(a, a, p, ii); b >>= 1;} return res;}
int euler_check(int n, int p) {return qpow(n, p - 1 >> 1, p);}
pair<int, int> solve(int a, int p)
{
    int r, x0, x1, ii;
    if(!a) return {0, 0};
    if(euler_check(a, p) != 1) return {-1, -1};
    while(euler_check((((r = rand() % (p - 2) + 1) * r % p - a) % p + p) % p, p) != p - 1);
    ii = ((r * r % p - a) % p + p) % p, x0 = qpow({r, 1}, p + 1 >> 1, p, ii).re, x1 = p - x0;
    return {min(x0, x1), max(x0, x1)};
}