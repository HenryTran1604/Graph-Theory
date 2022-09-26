#include <bits/stdc++.h>
using namespace std;
int n, m, s;
vector <int> adj[100];
bool used[100], ok = 0;
int X[100];
void inp()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		adj[i].clear();
	}
	for(int i = 0 ; i < m; i++)
	{
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
}
void Hmt(int k)
{
	if(k == n+1)
	{
		ok = 1;
		return;
	}
	if(ok) return;
	for(int v : adj[X[k-1]])
	{
		if(!used[v])
		{
			X[k] = v;
			used[v] = 1;
			Hmt(k+1);
			used[v] = 0;
		}
	}
}
void Hamilton_cycle()
{
	for(int i = 1; i <= n; i++)
	{
		if(ok) return;
		memset(used, 0, sizeof(used));
		X[1] = i;
		used[i] = 1;
		Hmt(2);
	}
	
}
int main()
{
	int t; cin >> t;
	while(t--)
	{
		inp(); s = 1; ok = 0;
		Hamilton_cycle();
		cout << ok << endl;
	}
	return 0;
}
/*Code by: Tran Quang Huy*/
