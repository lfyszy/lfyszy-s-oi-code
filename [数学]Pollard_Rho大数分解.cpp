int qmul(int a, int b, int p) {return (a * b - (int)((long double) a / p * b) * p + p) % p;}//O(1)龟速乘
int f(int x, int c, int p) {return (qmul(x, x, p) + c) % p;}
#define gcd __gcd
int pollar_rho(int p)
{
    if(p % 2 == 0) return 2;
#define step 127
    bool isfind = false;
    int c, r1, r2, pd = 1, tp, res = 0;
    while(!isfind)
    {
        c = rand() % (p - 1) + 1, r1 = r2 = 0;
        do
        {
            for(int i = 1; i <= step; i ++)
            {
                r1 = f(r1, c, p), r2 = f(f(r2, c, p), c, p);
                if(r1 == r2 || !(tp = qmul(pd, abs(r2 - r1), p))) break;
                pd = tp;
            }
            res = gcd(pd, p);
            if(res > 1) isfind = true;
        } while(!isfind && r1 != r2);
    }
    return res;
}