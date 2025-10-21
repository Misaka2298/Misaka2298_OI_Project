// Problem: 高精度除法
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/796/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Time: 2025-10-20 20:44:07

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;

string a;

VI Div(VI &A, int B, int &r)
{
	VI C;
	r = 0;
	for(int i = A.size()-1 ; i >= 0 ; i --)
	{
		r = r * 10 + A[i];
		C.push_back(r / B);
		r %= B;
	}
	
	reverse(C.begin(), C.end());
	while(C.size() > 1 && C.back() == 0)
		C.pop_back();
	return C;
}

signed main()
{
	int b;
	cin >> a >> b;
	VI A;
	
	for(int i = a.size()-1 ; i >= 0 ; i --)
		A.push_back(a[i] - '0');
	
	int r;
	auto C = Div(A, b, r);
	
	reverse(C.begin(), C.end());
	for(auto i : C)
		cout << i ;
	cout << endl << r;
}