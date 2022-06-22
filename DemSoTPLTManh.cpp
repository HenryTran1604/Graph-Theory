#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m;
vector <int> adj[1001], r_adj[1001];
bool visited[1001];
stack <int> stk;
void inp()
{
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		r_adj[y].push_back(x);
	}
}
void dfs1(int u)
{
	visited[u] = 1;
	for(int v : adj[u])
	{
		if(visited[v] == 0)
		{
			dfs1(v);
		}
	}
//	cout << u << " ";
	stk.push(u);
}
void dfs2(int u)
{
	visited[u] = 1;
	cout << u << " ";
	for(int v : r_adj[u])
		if(visited[v] == 0)
			dfs2(v);
}
void SCC()
{
	memset(visited, 0, sizeof(visited));
	
	for(int i = 1; i <= n; i++)
	{
		if(visited[i] == 0)
			dfs1(i);	
	}
//	cout << endl;
	memset(visited, 0, sizeof(visited));
	while(stk.empty() == 0)
	{
		int u = stk.top(); stk.pop();
		if(visited[u] == 0)	
		{
			dfs2(u);
			cout << endl;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; t = 1;
	while(t--)
	{
		inp();
		SCC();
	}
	return 0;
}
