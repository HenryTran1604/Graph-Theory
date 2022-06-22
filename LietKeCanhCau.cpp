#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m;
vector <int> adj[1001];
bool visited[1001];
vector <pair <int, int>> edge;
void inp()
{
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
		edge.push_back({x, y});
	}
}
void dfs(int u, int s, int t)
{
	visited[u] = 1;
	for(int v : adj[u])
	{
		if((u == s && v == t)||(u == t && v == s))
			continue;
		if(visited[v] == 0)
		{
			dfs(v, s, t);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--)
	{
		inp();
		vector <pair <int, int>> bridge;
		for (auto it : edge)
		{
			// loai bo canh hien tai
			memset(visited, 0, sizeof(visited));
			dfs(1, it.first, it.second);
			bool ok = 0;
			for(int j = 1; j <= n; j++)
			{
				if(visited[j] == 0)
				{
					ok = 1; break;
				}
			}
			if(ok == 1)
				bridge.push_back(it);
		}
		sort(bridge.begin(), bridge.end());
		for(auto it : bridge)
		{
			cout << it.first << " " << it.second << " ";
		}
		cout << endl;
		for(int i = 1; i <= n; i++)
			adj[i].clear();
		edge.clear();
	}
	return 0;
}
