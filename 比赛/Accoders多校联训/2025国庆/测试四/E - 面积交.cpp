// E
// expect pts = 10 +
// expect diff = i dont fk know
// 这道计算几何放在这里是······？

#include <bits/stdc++.h>
using namespace std;

double x, y, r;
double xx, yy, rr;

signed main()
{
	//freopen("area.in", "r", stdin);
	//freopen("area.out", "w", stdout);
	cin >> x >> y >> r >> xx >> yy >> rr;
	double ans = min(r, rr) * min(r, rr) * 3.1415926535;
	printf("%.2lf", ans);
}