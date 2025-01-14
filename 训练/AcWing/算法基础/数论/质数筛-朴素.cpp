//https://www.acwing.com/activity/content/problem/content/937/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000010;

int primes[maxn], cnt;
bool st[maxn];

void get_primes(int n)
{
    for (int i = 2; i <= n; i ++ )
    {
        if (st[i]) continue;
        primes[cnt ++ ] = i;
        for (int j = i + i; j <= n; j += i)
            st[j] = true;
    }
}

int main()
{
    int n;
    cin >> n;

    get_primes(n);

    cout << cnt << endl;

    return 0;
}