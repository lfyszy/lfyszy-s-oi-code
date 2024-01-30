const int N = /*max num*/;
bool st[N];
int phi[N];
vector<int> p;
void getprime(int n)
{
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