#include <bits/stdc++.h>
using namespace std;
int n, m, s, t;
vector <int> adj[1001];
bool visited[1001];
int parent[1001];
void bfs(int u)
{
	queue <int> q;
	q.push(u); visited[u] = 1;
	while(q.empty() == 0)
	{
		int v = q.front(); q.pop();
		for(int x : adj[v])
		{
			if(visited[x] == 0)
			{
				q.push(x);
				visited[x] = 1;
				parent[x] = v;
			}
		}
	}
}
void Path(int s, int t)
{
	memset(visited, 0, sizeof(visited));
	memset(parent, 0, sizeof(parent));
	bfs(s);
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
		cin >> n >> m >> s >> t;
		for(int i = 1; i <= n; i++)
			adj[i].clear();
		for(int i = 0; i < m; i++)
		{
			int x, y; cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		Path(s, t);
	}
	
	return 0;
}
