// A
// expect pts = 100
// expect diff = red
#include <bits/stdc++.h>
using namespace std;
const int maxn = 300;
 
int cnt[maxn];
 
signed main()
{
    freopen("data.in", "r", stdin);
    freopen("user.out", "w", stdout);
    string str;
    cin >> str;
    for(int i = 0 ; i < str.size() ; i ++)
        cnt[(int)str[i]-'a'] ++;
    for(int i = 0 ; i < 26 ; i ++)
        cout << cnt[i] << endl;
}
