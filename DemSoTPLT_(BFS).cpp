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
void bfs(int u)
{
	queue <int> Q;
	Q.push(u);
	visited[u] = 1;
	while(Q.empty() != 1)
	{
		int v = Q.front();
		Q.pop();
		for(int x : adj[v])
		{
			if(visited[x] == 0)
			{
				Q.push(x);
				visited[x] = 1;
			}
		}
	}
}
void ConnetedComponent() // using bfs
{
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		if(visited[i] == 0)
		{
			ans++;
			bfs(i);
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
