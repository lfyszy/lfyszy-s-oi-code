struct prime {int val, cnt;};
vector<prime> dip;
void divide(int n)
{
    dip.clear();
    for(int i = 2; i <= n / i; i ++)
        if(n % i == 0)
        {
            int s = 0;
            while(n % i == 0)
                n /= i, s ++;
            dip.push_back({i, s});
        }
    if(n > 1) dip.push_back({n, 1});
}