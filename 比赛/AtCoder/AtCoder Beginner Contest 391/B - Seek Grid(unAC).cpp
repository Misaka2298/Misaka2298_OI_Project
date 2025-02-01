#include <bits/stdc++.h>
using namespace std;
const int maxn = 55;

bool s[maxn][maxn], t[maxn][maxn];
int n, m, divv;

signed main()
{
    cin >> n >> m;
    divv = n - m + 1; // 修正循环范围
    if(n == m)
    {
        cout << "1 1";
        return 0;
    }
    
    char chr;
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= n ; j++)
        {
            cin >> chr;
            if(chr == '#') s[i][j] = true;
        }
    for(int i = 1 ; i <= m ; i++)
        for(int j = 1 ; j <= m ; j++)
        {
            cin >> chr;
            if(chr == '#') t[i][j] = true;
        }
        
    for(int i = 1 ; i <= divv ; i++)
        for(int j = 1 ; j <= divv ; j++)
        {
            ret: bool flag = true;
            for(int k = 1 ; k <= m ; k++)
                for(int l = 1 ; l <= m ; l++)
                {
                    if(s[i+k-1][j+l-1] != t[k][l])
                    {
                        flag = false;
                        goto ret;
                    }
                }
            if(flag)
            {
                cout << i << ' ' << j;
                return 0;
            }
        }
    return 0;
}