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

struct vertex{
	int id, deg, available, color;
};
vertex V[100];
int n, m, s;
vector <int> adj[100];
bool cmp(vertex a, vertex b){
	return a.deg > b.deg;
}
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
	for(int i = 1; i <= n; i++){
		sort(all(adj[i]));
		V[i].id = i;
		V[i].deg = adj[i].size();
		V[i].color = -1;
	}
	sort(V+1, V+n+1, cmp);
}
bool check(){
	for(int i = 1; i <= n; i++){
		if(V[i].color == -1)
			return 1;
	}
	return 0;
}
void coloring(){
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(V[i].color == -1){
			cnt++;
			V[i].color = cnt; V[i].deg = 0;
			vector <int> tmp; tmp.push_back(V[i].id);
			for(int j = 1; j <= n; j++){
				if(binary_search(all(adj[V[j].id]), V[i].id) == 0 && // dinh V[i].id khong ke voi dinh V[j].id
					binary_search(all(tmp), V[j].id) == 0 && V[j].color == -1){ // dinh V[j].id khong ke voi cac dinh da co mau cnt
					tmp.push_back(V[j].id); // danh dau la da thuoc mau cnt
					V[j].color = cnt; V[j].deg = 0;
				}
			}
		}
	}
//	for(int i = 1; i <= n; i++){
//		cout << V[i].id << ":" << V[i].color << " ";
//	}
//	cout << cnt << " ";
	if(cnt > s) cout << "NO\n";
	else cout << "YES\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
	while(t--){
		inp();
		coloring();
	}
}


/*Code by: Tran Quang Huy*/
