#include <bits/stdc++.h>
using namespace std;

int n, m, xp;
vector <int> adj[1001];
bool visited[1001];
void inp()
{
	cin >> n >> m >> xp;
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
	cout << u << " ";
	visited[u] = 1; // da den tham
	for(int v : adj[u])
	{
		if(visited[v] == 0)
			dfs(v);
	}
}
int main()
{
	int t; cin >> t;
	while(t--)
	{
		inp();
		dfs(xp);
		cout << endl;
	}
	return 0;
}
