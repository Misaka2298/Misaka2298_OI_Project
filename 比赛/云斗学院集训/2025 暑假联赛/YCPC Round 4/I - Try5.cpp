#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
typedef long long LL;
typedef pair<int, int> PII;
#define endl '\n'

LL T, n, k;
char str[maxn];
LL range0cnt;

void init()
{
    range0cnt = 0;
}

signed main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin >> T;
    while (T--)
    {
        init();
        cin >> n >> k;
        for (int i = 1; i <= n; i ++)
            cin >> str[i];
        
        bool flag = false;
        for (int i = 1; i <= n; i ++)// str-init
        {
            if (str[i] == '0')
            {
            	if (!flag)
                    flag = true;
            }
            else
                if (flag)
                {
                	flag = false;
                    range0cnt++;
                }
         
        }
        if (flag)
            range0cnt++;
        if (k >= range0cnt)
        {
            LL rem = k - range0cnt;
            if (rem % 2 == 0)
            {
                for (int i = 1; i <= n; i ++)
                {
                    cout << '1';
                }
            }
            else
            {
                for (int i = 1; i <= n - 1; i ++)
                {
                    cout << '1';
                }
                cout << '0';
            }
            cout << endl;
            continue;
        }
        flag = false;
        for (int i = 1; i <= n; ++i)
        {
            if (str[i] == '1')
            {
                cout << '1';
                if (flag)
                {
                    flag = false;
                    k--;
                }
            }
            else
            {
                if (k > 0)
                {
                    cout << '1';
                    flag = true;
                }
                else
                {
                    cout << '0';
                }
            }
        }
        cout << endl;
    }
    return 0;
}