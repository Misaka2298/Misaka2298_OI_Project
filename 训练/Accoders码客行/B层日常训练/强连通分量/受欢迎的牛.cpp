#include <bits/stdc++.h>
using namespace std;
// 最大的节点/边界（视题目最大 n 而定）。这里取较大安全上界，避免越界。
// 注意：如果题目 n 很大（接近 1e6），这会使用较多内存，确保环境允许。
const int maxn = 1e6+10;

int n, m; // 图的节点数 n、边数 m

// 邻接表存储：
// e[i] 存储第 i 条边的终点（to）
// ne[i] 存储第 i 条边的下一个边的索引（链表的 next）
// h[u] 存储以 u 为起点的第一条边的索引（head）
// idx 为当前边的索引（从 0 开始递增）
int e[maxn], ne[maxn], h[maxn], idx;

// Tarjan 维护的变量：
// stk: 用作栈，保存当前搜索路径上的节点
// times: 时间戳计数器，用于给 dfn 编号
// dfn[u]: 节点 u 的访问序号（发现时间）
// low[u]: 节点 u 能回溯到的最早 dfn（low-link 值）
// top: 栈顶指针（stk 的索引）
// st[u]: 标志位，表示 u 是否在栈中（用于判断反向边/横向边）
// id[u]: u 属于的强连通分量编号（缩点后编号）
// scc_cnt: 已发现的强连通分量个数
// sz[i]: 第 i 个强连通分量包含的原始节点个数
int stk[maxn], times, low[maxn], id[maxn], dfn[maxn];
int top;
bool st[maxn];
int scc_cnt, dout[maxn], sz[maxn];

void tarjan(int u)
{
	// 经典 Tarjan 算法主体：
	// 1) 进入节点 u，设置 dfn 和 low
	// 2) 将 u 压入栈，标记为在栈中
	// 3) 遍历 u 的每条出边 (u->j)，若 j 未访问则递归，同时更新 low[u]
	//    若 j 已访问且在栈中，说明存在回边，更新 low[u] 为 dfn[j]
	// 4) 若 dfn[u] == low[u]，说明 u 是一个强连通分量的根，弹栈直到弹出 u
	dfn[u] = low[u] = ++times;
	stk[++top] = u; // 将 u 入栈
	st[u] = 1; // 标记 u 在栈中

	// 遍历邻接表的出边
	for(int i = h[u] ; i != -1 ; i = ne[i])
	{
		int j = e[i]; // 边 u->j 的终点
		if(!dfn[j])
		{
			// 还没被访问，继续深搜
			tarjan(j);
			// 递归返回后，j 的 low 已经确定，用它来松弛 u 的 low
			low[u] = min(low[u], low[j]);
		}
		else if(st[j])
		{
			// j 已访问并且在栈中，说明有回边或横向边到栈内节点
			// 用 j 的 dfn 更新 u 的 low（注意这里用 dfn[j] 而不是 low[j]）
			low[u] = min(low[u], dfn[j]);
		}
	}

	// 如果 u 是一个 SCC 的根（即无法再回退到比 dfn[u] 更小的点）
	if(dfn[u] == low[u])
	{
		++scc_cnt; // 发现一个新的强连通分量
		int y;
		// 弹栈，直到弹出 u，期间把这些节点标记为属于当前 scc
		do
		{
			y = stk[top--];
			st[y] = 0; // 标记不在栈中
			id[y] = scc_cnt; // 记录节点 y 属于第 scc_cnt 个强连通分量
			sz[scc_cnt] ++; // 统计该强连通分量的大小
		} while(y != u);
	}
}

void addedge(int a, int b)
{
	// 在邻接表头插法插入边 a->b
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

signed main()
{
	// 读入图
	cin >> n >> m;

	// 初始化邻接表 head 数组为 -1（表示当前无边）
	memset(h, -1, sizeof h);

	for(int i = 1 ; i <= m ; i ++)
	{
		int a, b;
		cin >> a >> b;
		// 添加有向边 a -> b
		addedge(a, b);
	}

	// 对每个尚未访问的节点运行 Tarjan，分配 scc id
	for(int i = 1 ; i <= n ; i ++)
		if(!dfn[i])
			tarjan(i);

	// 构建缩点图（把每个 SCC 看作一个超级节点），统计每个 SCC 的出度 dout
	// 遍历原图的每条边 i->k，若 id[i] != id[k]，则这个边在缩点图中是 id[i] -> id[k]
	// 我们只需要知道每个 SCC 是否有出边（out-degree），因此只计数 dout[id[i]]
	for(int i = 1 ; i <= n ; i ++)
		for(int j = h[i] ; j != -1 ; j = ne[j])
		{
			int k = e[j];
			int a = id[i], b = id[k];
			if(a != b)
				dout[a] ++; // a 在缩点图中有一条指向 b 的出边
		}

	// 题目逻辑（受欢迎的牛）通常是：如果缩点图中恰好存在一个出度为 0 的 SCC，
	// 那么所有位于该 SCC 的原始节点都是答案（可以被任何其他节点到达，但它们不向外）
	// 否则答案为 0（没有唯一的“汇聚”强连通分量）。下面统计出度为 0 的 SCC 个数并累加其大小。
	int zeros = 0, sum = 0;
	for(int i = 1 ; i <= scc_cnt ; i ++)
		if(!dout[i])
		{
			zeros ++;        // 出度为 0 的 SCC 个数
			sum += sz[i];    // 累加该 SCC 的节点数
			if(zeros > 1)
			{
				// 如果不止一个出度为 0 的 SCC，则答案为 0（题目要求必须唯一）
				sum = 0;
				break;
			}
		}

	cout << sum;
}