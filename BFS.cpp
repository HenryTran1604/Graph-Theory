#include <bits/stdc++.h>
using namespace std;
int n, m;
vector <int> adj[1001];
bool visited[1001];
void inp()
{
	cin >> n >> m;
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
	visited[u] = 1; // u da duoc tham
	
	while(Q.empty() != 1)
	{
		int v = Q.front();
		cout << v << " ";
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
int main()
{
	inp();
	bfs(1);
	return 0;
}
