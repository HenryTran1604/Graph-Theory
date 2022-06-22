#include <bits/stdc++.h>
using namespace std;
int n, m;
vector <int> adj[1001];
bool visited[1001];
vector <int> topo;
void inp()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		adj[i].clear();
	
	for(int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
	}
	memset(visited, 0, sizeof(visited));   
	
}
void dfs(int u)
{
	visited[u] = 1;
	for(int v : adj[u])
		if(visited[v] == 0)
			dfs(v);
	topo.push_back(u);
}
int main()
{
	inp();
	for(int i = 1; i <= n; i++)
	{
		if(visited[i] == 0)
			dfs(i);
	}
	reverse(topo.begin(), topo.end());
	for(int x : topo)
		cout << x << " ";
	
	return 0;
}
//7 7
//1 2
//2 3
//2 4
//3 5
//4 5
//1 6
//7 6
