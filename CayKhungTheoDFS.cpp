#include <bits/stdc++.h>
#define ft first
#define sd second
#define pii pair<int, int>
#define toint(a) a-'0'
#define all(a) a.begin(), a.end()
#define endl '\n'
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
const int maxn = 1e5+1;
int n, m, s, used[maxn];
vector <int> adj[maxn];
vector <pii> T;
void inp(){
	cin >> n >> m >> s;
	for(int i = 1; i <= n; i++){
		adj[i].clear();
	}
	for(int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(used, 0, sizeof(used));
	T.clear();
}
void DFS(int u){
	used[u] = 1;
	for(int v : adj[u]){
		if(!used[v]){
			T.push_back({u, v});
			DFS(v);
		}
	}
}
void solve(){
	DFS(s);
	if(T.size() != n-1) cout << -1 << endl;
	else{
		for(pii x : T){
			cout << x.ft << " " << x.sd << endl;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int test; cin >> test;
	while(test--)
	{
		inp();
		solve();
	}
	return 0;
}

/*Code by: Tran Quang Huy*/
