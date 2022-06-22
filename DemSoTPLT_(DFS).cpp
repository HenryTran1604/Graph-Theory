#include <bits/stdc++.h>
using namespace std;
int n, m;
vector <int> adj[1001];
bool visited[1001];
void inp()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		adj[i].clear();
	for(int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(visited, 0, sizeof(visited));
}
void dfs(int u)
{
	visited[u] = 1;
	for(int v : adj[u])
	{
		if(visited[v] == 0)
		{
			dfs(i);
		}
	}
}
void ConnectedComponent()
{
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		if(visited[i] == 0)
		{
			ans++;
			dfs(i);
		}
	}
	cout << ans << endl;
}
int main()
{
	int t; cin >> t;
	while(t--)
	{
		inp();
		ConnectedComponent();
	}
	return 0;
}
