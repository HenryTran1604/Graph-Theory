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
void BFS(int u){
	queue <int> q;
	q.push(u); 
	used[u] = 1;
	while(!q.empty()){
		int v = q.front(); q.pop();
		for(int i : adj[v]){
			if(!used[i]){
				T.push_back({v, i});
				used[i] = 1;
				q.push(i);
			}
		}
	}
}
void solve(){
	BFS(s);
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
