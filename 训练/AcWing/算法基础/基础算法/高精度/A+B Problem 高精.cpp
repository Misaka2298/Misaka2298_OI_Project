// Problem: P1601 A+B Problem（高精）
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1601
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Time: 2025-10-20 19:50:00

#include <bits/stdc++.h>
using namespace std;

string a, b;

vector<int> Add(vector<int> &A, vector<int> &B)
{
	if(A.size() < B.size())
		return Add(B, A);
	int t = 0;
	vector<int> C;
	for(int i = 0 ; i < A.size() ; i ++)
	{
		t += A[i];
		if(i < B.size())
			t += B[i];
		C.push_back(t%10);
		t /= 10;
	}
	if(t)
		C.push_back(t);
	return C;
}

signed main()
{
	vector<int> A, B;
	cin >> a >> b;
	for(int i = a.size()-1 ; i >= 0 ; i --)
		A.push_back(a[i] - '0');
	for(int i = b.size()-1 ; i >= 0 ; i --)
		B.push_back(b[i] - '0');
	
	auto C = Add(A, B);
	
	reverse(C.begin(), C.end());
	for(auto i : C)
		cout << i;
}