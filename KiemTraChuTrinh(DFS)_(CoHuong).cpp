#include <bits/stdc++.h>
using namespace std;
int n, m, st, en;
vector <int> adj[1001];
int color[1001];
void inp()
{
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
	}
}
bool DFS(int u)
{
	color[u] = 1;// mau xam
	for(int v : adj[u])
	{
		if(color[v] == 0)
		{
			if(DFS(v))
				return true;
		}
		else if(color[v] == 1)
		{
			return true;
		}
	}
	color[u] = 2; // mau den
	return false;
}
int main()
{
	inp();
	bool logic = 0;
	for(int i = 1; i <= n; i++){
		if(color[i] == 0)
		{
			if(DFS(i))
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
//3 1
//1 2
//5 3
//1 5
//2 4
//4 5
