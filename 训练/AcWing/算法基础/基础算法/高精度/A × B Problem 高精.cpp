// Problem: 高精度乘法
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/795/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Time: 2025-10-20 20:35:08

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;

string a;
int b;

VI Mul(VI &A, int b)
{
	VI C;
	
	int t = 0;
	for(int i = 0 ; i < A.size() || t ; i ++)
	{
		if(i < A.size())
			t += A[i] * b;
		C.push_back(t % 10);
		t /= 10;
	}
	
	while(C.size() > 1 && C.back() == 0)
		C.pop_back();
	return C;
}

signed main()
{
	cin >> a >> b;
	VI A;
	
	for(int i = a.size()-1 ; i >= 0 ; i --)
		A.push_back(a[i] - '0');
	
	auto C = Mul(A, b);
	
	reverse(C.begin(), C.end());
	for(int i : C)
		cout << i;
}