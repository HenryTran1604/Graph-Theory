
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n, m;
vector <int> adj[1001], r_adj[1001];
bool used[1001];
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
}
void dfs(int u)
{
	used[u] = 1;
	for(int v : adj[u])
		if(!used[v])
			dfs(v);
}

void solve()
{
	int tmp = 0, cnt = 0;
	for(int i = 1; i <= n; i++)
	{
	    cnt = 0; memset(used, 0, sizeof(used));
	    used[i] = 1;
	    for(int j = 1; j <= n; j++)
	    {
	        if(!used[j])
           {
               cnt++;
               dfs(j);
           }
	    }
		if(cnt != 1) cout << i << " ";
	}
	cout << endl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int test; cin >> test;
	while(test--)
	{
		inp();
		solve();
	}
	return 0;
}
/*Code by: Tran Quang Huy*/

/*Code by: Tran Quang Huy*/
