// I another try
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> PLL;
#define endl '\n'
const int maxn = 2e5 + 10;
LL T;
LL n, k;
char str[maxn];
vector<PLL> substr0;
bool flag = 0;

signed main()
{
    cin >> T;
    while (T--)
    {
        substr0.clear();
        memset(str, 0, sizeof str);
        flag = 0;
        cin >> n >> k;// >> str+1;
        for(int i = 1; i <= n; i ++)
        	cin >> str[i];
        LL l = 0, r = 0;
        for (LL i = 1; i <= n; i ++)
        {
            if (str[i] == '0')
            {
                if (!flag)
                    l = i, flag = 1;
                r = i;
            }
            else if (flag)
            {
                substr0.push_back({l, r});
                flag = 0;
            }
        }
        if (flag)
            substr0.push_back({l, r});
        if (n == 1)
        {
            if (k % 2 != 0)
                puts(str[1] == '0' ? "1" : "0");
            else
                puts(str[1] == '0' ? "0" : "1");
            continue;
        }
        if (substr0.empty() && k == 1)
        {
            str[n] = '0';
            puts(str + 1);
            continue;
        }
        LL sz = substr0.size();
        for (LL i = 0; i < min(sz, k); i++)
        {
            pair<LL, LL> qj = substr0[i];
            for (LL j = qj.first; j <= qj.second; ++j)
                str[j] = '1';
        }
        puts(str + 1);
    }
    return 0;
}