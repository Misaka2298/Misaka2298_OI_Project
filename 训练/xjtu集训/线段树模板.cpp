#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10; // 常量：数组最大长度（1-based），留有缓冲空间

int n, m; // 全局变量：n 为元素个数，m 为操作数
long long a[maxn]; // 存放原数组（1-based），使用 long long 以防溢出

// 线段树节点结构体：记录区间左右端点、区间和、延迟标记
struct node{
    int l,r; // 区间左右端点
    long long sum,lazy; // sum 表示区间和，lazy 表示延迟加值
}t[maxn * 4]; // 线段树数组，大小为 4*n 常用上界

// 合并子节点：将左右子节点的和合并到父节点
void pushup(int u)
{
    t[u].sum = t[u*2].sum + t[u*2+1].sum; // 父节点的和等于左右子节点之和
}

// 将当前节点的 lazy 下推到子节点（把延迟更新传播下去）
// 注意更新子节点的 sum 与 lazy 两个成员
void pushdown(int u)
{
    if(t[u].lazy == 0) // 如果没有延迟标记则直接返回
        return; // 无需下推
    t[u*2].lazy += t[u].lazy; // 将当前延迟累加到左子节点的 lazy
    t[u*2+1].lazy += t[u].lazy; // 将当前延迟累加到右子节点的 lazy
    t[u*2].sum += (t[u*2].r - t[u*2].l+1) * t[u].lazy; // 更新左子节点的区间和
    t[u*2+1].sum += (t[u*2+1].r - t[u*2+1].l+1) * t[u].lazy; // 更新右子节点的区间和
    t[u].lazy = 0; // 清空当前节点的延迟标记
}

// 建树：在区间 [l,r] 上建立线段树节点 u
// 叶子节点直接赋值为原数组 a[l]
void build(int u,int l,int r)
{
    t[u].l = l; // 记录当前节点的左端点
    t[u].r = r; // 记录当前节点的右端点
    if(l==r) // 如果区间只包含一个元素（叶子节点）
    {
        t[u].sum = a[l]; // 叶节点的和等于原数组该位置的值
        return; // 建树结束
    }

    int mid = (l+r)>>1; // 计算中点（右移一位等价于除以2）
    build(u*2, l, mid); // 递归建立左子树
    build(u*2+1, mid+1, r); // 递归建立右子树
    pushup(u); // 建立完子节点后合并到父节点
}

// 区间加值（带延迟标记）：将区间 [l,r] 的每个元素加上 x
// 如果当前节点完全被覆盖，则直接更新 sum 与 lazy；否则下推并递归
void change(int u,int l,int r,int x)
{
    if(l<=t[u].l && t[u].r <= r) // 如果当前节点区间被更新区间完全覆盖
    {
        t[u].sum += (t[u].r-t[u].l+1) * x; // 更新当前节点的区间和
        t[u].lazy += x; // 累加延迟标记
        return; // 完成该节点的更新，无需再向下递归
    }
    if(t[u].l > r || t[u].r < l) // 如果当前节点区间与更新区间不相交
        return ; // 直接返回，不做任何处理
    pushdown(u); // 在需要访问子节点之前先下推延迟标记
    change(u*2, l, r, x); // 递归更新左子树
    change(u*2+1, l, r, x); // 递归更新右子树
    pushup(u); // 在更新子节点后合并父节点信息
}

// 区间求和：返回区间 [l,r] 的和
// 注意边界判断与在非完全覆盖时要下推 lazy
int query(int u,int l,int r)
{
    if(l<=t[u].l && t[u].r <= r) // 如果当前节点区间被查询区间完全覆盖
        return t[u].sum; // 直接返回当前节点的区间和
    if(t[u].l > r || t[u].r < l) // 如果当前节点区间与查询区间不相交
        return 0; // 对于和的查询返回 0（中性元素）
    pushdown(u); // 在继续查询子节点前下推延迟标记，保证子节点数据正确
    return query(u*2, l, r) + query(u*2+1, l, r); // 合并左右子树的查询结果并返回
}

signed main()
{
    // 输入：n 元素个数，m 操作数（1 表示区间加，其他表示区间求和）
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++)
		cin >> a[i];
	build(1, 1, n); // 从根节点 1 开始在区间 [1,n] 上建树
	
	long long opt, l, r, k;
	while(m--) 
	{
		cin >> opt >> l >> r; // 读取操作类型与区间端点
		if(opt == 1) // 如果是类型 1，表示区间加操作asfdgsfghjhjgljasdfeqwerzxcv
		{
			cin >> k; // 读取要加的值 k
			change(1, l, r, k); // 对区间 [l,r] 加上 k，从根节点 1 开始
		}
		else // 否则视为区间求和操作
			cout << query(1, l, r) << endl; // 输出区间 [l,r] 的和，并换行
	}
}