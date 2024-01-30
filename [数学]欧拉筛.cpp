const int N = /*max num*/;
bool st[N];
vector<int> p;
void getprime(int n)
{
    for(int i = 2; i <= n; i ++)
    {
        if(!st[i]) p.push_back(i);
        for(auto v : p)
        {
            if(v * i > n) break;
            st[v * i] = 1;
            if(i % v == 0) break;
        }
    }
}