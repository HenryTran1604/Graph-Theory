#include <bits/stdc++.h>
using namespace std;
int n, m;
vector <int> adj[1001];
//bool visited[1001];
vector <int> topo;
int inc[1001]; // mang luu ban bac vao
void inp()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		adj[i].clear();
	memset(inc, 0, sizeof(inc));
	for(int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		inc[y]++;
	}
//	memset(visited, 0, sizeof(visited));   
	
}
void kahn()
{
	queue <int> q;
	for(int i = 1; i <= n; i++)
	{
		if(inc[i] == 0)
			q.push(i);
	}
	while(q.empty() == 0)
	{
		int u = q.front(); q.pop();
		topo.push_back(u);
		for(int v : adj[u])
		{
			inc[v]--;
			if(inc[v] == 0)
				q.push(v);
		}
	}
	for(int x : topo)
		cout << x << " ";
	cout << endl;
}
int main()
{
	inp();
	kahn();
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
