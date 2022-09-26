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
int n, m;
const int INF = 1e9;
vector <int> d;
struct edge{
	int u, v, w;
};
vector <edge> e;
int par[1001];
void inp(){
	e.clear();
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y, z; cin >> x >> y >> z;
		e.push_back({x, y, z});
	}
}
void init(){
	d.clear(); d.resize(n+1, INF);
	memset(par, -1, sizeof(par));
}
void bellmanFord(int s){
	d[s] = 0;
	for(int T= 1; T < n; T++){
		for(auto x : e){
			int u = x.u, v = x.v, w = x.w;
			if(d[u] != INF && d[v] > d[u] + w){
				d[v] = d[u] + w;
				par[v] = u;
			}
		}
	}
}
bool check(){
	for(auto x : e){
		int u = x.u, v = x.v, w = x.w;
		if(d[u] != INF && d[v] > d[u] + w){
			return 1;
		}
	}
	return 0;
}
void solve(){
	for(int i = 1; i <= n; i++){
		init();
		bellmanFord(i);
		if(check()){
			cout << 1 << endl;
			return;
		}
	}
	cout << 0 << endl;
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
