#include <bits/stdc++.h>
using namespace std;

int count(int n) 
{
    int max_sum;
    if (n % 2 == 0) {
        max_sum = (n * n) / 2;
    } else {
        max_sum = (n * n - 1) / 2;
    }
    return (max_sum / 2) + 1;
}

signed main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        int n;
        cin >> n;
        cout << count(n) << endl;
    }
    return 0;
}