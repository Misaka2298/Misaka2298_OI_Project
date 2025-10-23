// B
// expect pts = 100
// expect diff = orange
 
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
typedef long long LL;
#define endl '\n'
 
int n, q;
LL a[maxn];
LL suma, suma2;
 
signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("data.in", "r", stdin);
    freopen("user.out", "w", stdout);
    cin >> n >> q;
    for(int i = 1 ; i <= n ; i ++)
        cin >> a[i];
    for(int i = 1 ; i <= n ; i ++)
        suma += a[i], suma2 += a[i]*a[i];
 
    while(q --)
    {
        LL k;
        cin >> k;
        LL ans = suma2 + n*k*k + 2*k*suma;
        cout << ans << endl;
    }
 
}