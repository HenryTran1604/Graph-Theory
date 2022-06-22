#include <bits/stdc++.h>
using namespace std;
int n, m, st, en;
vector <int> adj[1001];
bool visited[1001];
int parent[1001];
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
bool BFS(int u)
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
				q.push(x); visited[x] = 1;
				parent[x] = v;
			}
			else if(x != parent[v])
			{
				return true;
			}
		}
	}
	return false;
}
int main()
{
	cout << "Kiem tra chu trinh bang BFS do thi vo huong\n";
	inp();
	bool logic = 0;
	for(int i = 1; i <= n; i++){
		if(visited[i] == 0)
		{
			if(BFS(i))
			{
				cout << "YES";
				logic = 1;
				break;
			}
		}
	}
	if(logic == 0) cout << "NO";
	return 0;
}
//5 6
//1 3
//1 2
//5 3
//1 5
//2 4
//4 5
