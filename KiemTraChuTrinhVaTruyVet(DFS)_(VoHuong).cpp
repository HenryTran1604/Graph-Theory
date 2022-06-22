#include <bits/stdc++.h>
using namespace std;
int n, m, st, en;
vector <int> adj[1001];
bool visited[1001];
int parent[1001];
void inp()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		adj[i].clear();
	memset(visited, 0, sizeof(visited));
	for(int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(visited, 0, sizeof(visited));   
	
}
bool dfs(int u)
{
	visited[u] = 1;
	for(int v : adj[u])
	{
		if(visited[v] == 0)
		{
			parent[v] = u;
			if(dfs(v)) return true;
		}
		else if(v != parent[u])
		{
			st = v, en = u;
			return true;
		}
	}
	return false;
}
int main()
{
	int t; cin >> t;
	while(t--)
	{
		inp();
			bool logic = 0;
		for(int i = 1; i <= n; i++)
		{
			if(visited[i] == 0)
			{
				if(dfs(i) == 1)
				{
					cout << "YES\n";
					vector <int> cycle;
					cycle.push_back(st);
					while(en != st)
					{
						cycle.push_back(en);
						en = parent[en];
					}
					cycle.push_back(st);
					reverse(cycle.begin(), cycle.end());
					for(int x : cycle)
						cout << x << " ";
					logic = 1;
					break;
				}
			}
		}
		if(logic == 0) cout << "NO\n";
	}
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
