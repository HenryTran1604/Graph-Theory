#include <bits/stdc++.h>
#define fi first
#define sec second
#define pii pair<int, int>
#define toint(a) a-'0'
#define all(a) a.begin(), a.end()
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
int n, m, ok = 0;
stack <int> topo;
vector <int> adj[100005];
int color[100005];
int parent[100005];
void inp(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
	}
}
void dfs(int u){
	color[u] = 1; // dang tham
	for(int v : adj[u]){
		if(color[v] == 0){
			dfs(v);
		}
		else if(color[v] == 1){
			ok = 1;
//			return;
		}
	}
	color[u] = 2;
	topo.push(u);
}
void solve(){
	for(int i = 1; i <= n; i++){
		if(!color[i]){
			dfs(i);
		}
	}	
	if(ok) cout << "IMPOSSIBLE";
	else{
		while(!topo.empty()){
			cout << topo.top() << " ";
			topo.pop();
		}
	}
	
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	inp();
	solve();
	
	return 0;
}


