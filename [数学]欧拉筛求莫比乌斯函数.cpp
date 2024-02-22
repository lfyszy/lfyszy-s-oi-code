const int N = /*max num*/;
int mu[N];
bool st[N];
vector<int> p;
void getprime(int n)
{
    mu[1] = 1;
    for(int i = 2; i <= n; i ++)
    {
        if(!st[i]) p.push_back(i), mu[i] = -1;
        for(auto j : p)
        {
            if(i * j > n) break;
            st[i * j] = 1;
            if(i % j == 0) {mu[i * j] = 0; break;}
            mu[i * j] = -mu[i];
        }
    }
}