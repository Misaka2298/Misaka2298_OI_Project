// Problem: 高精度减法
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/794/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Time: 2025-10-20 20:24:55

#include <bits/stdc++.h>
using namespace std;

string a, b;

bool aisbig(vector<int> &A, vector<int> &B)
{
	if(A.size() != B.size())
		return A.size() > B.size();
	
	for(int i = A.size()-1 ; i >= 0 ; i --)
		if(A[i] != B[i])
			return A[i] > B[i];
	return true;
}

vector<int> Sub(vector<int> &A, vector<int> &B)
{
	vector<int> C;
	int t = 0;
	for(int i = 0 ; i < A.size() ; i ++)
	{
		t = A[i] - t;
		if(i < B.size())
			t -= B[i];
		C.push_back((t+10)%10);
		if(t < 0)
			t = 1;
		else
			t = 0;
	}
	
	while(C.size() > 1 && C.back() == 0)
		C.pop_back();
	return C;
}

signed main()
{
	cin >> a >> b;
	vector<int> A, B;
	for(int i = a.size()-1 ; i >= 0 ; i --)
		A.push_back(a[i] - '0');
	for(int i = b.size()-1 ; i >= 0 ; i --)
		B.push_back(b[i] - '0');
		
	vector<int> C;
	
	if(aisbig(A, B))w
		C = Sub(A, B);
	else
		C = Sub(B, A), cout << '-';
		
	reverse(C.begin(), C.end());
	for(int i : C)
		cout << i;
		
		
		
		
}