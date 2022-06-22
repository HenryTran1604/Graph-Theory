#include <bits/stdc++.h>
using namespace std;
int n, m, s, t;
vector <int> adj[1001];
bool visited[1001];
int parent[1001];
void inp()
{
	cin >> n >> m >> s >> t;
	for(int i = 1; i <= n; i++)
		adj[i].clear();
	for(int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
}
void dfs(int u)
{
	visited[u] = 1;
	for(int v : adj[u])
	{
		if(visited[v] == 0)
		{
			parent[v] = u;
			dfs(v);
		}
	}
}
void Path(int s, int t)
{
	memset(visited, 0, sizeof(visited));
	memset(parent, 0, sizeof(parent));
	dfs(s);
	if(visited[t] == 0)
		cout << -1;
	else
	{
		vector <int> path;
		while(t != s)
		{
			path.push_back(t);
			t = parent[t];
		}
		path.push_back(s);
		reverse(path.begin(), path.end());
		for(int x : path)
			cout << x << " ";
	}
	cout << endl;
}
int main()
{
	int test; cin >> test;
	while(test--)
	{
		inp();
		Path(s, t);
	}
	return 0;
}
