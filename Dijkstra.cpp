#include <bits/stdc++.h>
#define fi first
#define sec second
#define pii pair<int, int>
#define toint(a) a-'0'
#define all(a) a.begin(), a.end()
#define endl '\n'
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
const ll INF = 1e18;
const int maxn = 1e5+1;

int n, m, s;
vector <pair<int, int>> adj[maxn];

void inp(){
	cin >> n >> m; s = 1;
	for(int i = 0; i < m; i++){
		int x, y, w; cin >> x >> y >> w;
		adj[x].push_back({y, w});
//		adj[y].push_back({x, w});
	}
}
void dijkstra(int s){
	vector <ll> d(n+1, INF);
	d[s] = 0;
	priority_queue <pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
	// {khoang cach, dinh}
	q.push({0, s});
	while(!q.empty()){
		pair<ll, int> top = q.top(); q.pop();
		int u = top.second; // dinh
		ll kc = top.first; // khoang cach
		if(kc > d[u]) continue;
		
		for(auto it : adj[u]){
			int v = it.first;
			int w = it.second;
			if(d[v] > d[u] + w){
				d[v] = d[u] + w;
				q.push({d[v], v});
			}
		}
	}
	for(int i = 1; i <= n; i++){
		cout << d[i] << " ";
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	inp();
	dijkstra(s);
	
}


/*Code by: Tran Quang Huy*/