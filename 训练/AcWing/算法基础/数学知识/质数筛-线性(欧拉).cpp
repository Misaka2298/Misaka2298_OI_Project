//https://www.acwing.com/problem/content/870/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;

int n, idx;
bool st[maxn];          // st[i]表示i是否被筛掉，true表示合数
vector<int> prime;      // 存储所有质数

int get_prime()
{
    for(int i = 2 ; i <= n ; i++)
    {
        if(!st[i]) prime.push_back(i);    // 如果i未被筛掉，则i是质数
        for(auto pri_j : prime)	          // 用已知的质数去筛合数
        {
            if(i * pri_j > n) break;      // 超出范围，退出内层循环
            st[i * pri_j] = true;         // 标记合数
            if(i % pri_j == 0) break;     // i是pri_j的倍数时退出，保证每个合数只被最小质因子筛掉
        }
    }
    int ans = 0;
    for(int i = 2 ; i <= n ; i++)        // 统计[2,n]中质数的个数
        if(!st[i]) ans++;
    return ans;
}

signed main()
{
	cin >> n;
	int ans = get_prime();
	cout << ans;
	return 0;
}