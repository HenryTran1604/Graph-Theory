#include <bits/stdc++.h>
#define ft first
#define sd second
#define pii pair<int, int>
#define toint(a) a-'0'
#define all(a) a.begin(), a.end()
#define endl '\n'
#define ms(a) memset(a, 0, sizeof(a))
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

int n, m;
vector <pii> edge;
int parent[1001], size[1001];
void inp(){
	edge.clear();
	ms(parent);
	ms(size);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		edge.push_back({x, y});
	}
}
void make_set(){
	for(int i = 1; i <= n; i++){
		parent[i] = i;
		size[i] = 1;
	}
}
int find(int v){
	if(v == parent[v])
		return v;
	return parent[v] = find(parent[v]);
}
bool Union(int a, int b){
	a = find(a); b = find(b);
	if(a == b) return 0;
	
	if(size[a] < size[b]){
		swap(a, b);	
	}
	parent[b] = a;
	size[a] += size[b];
	return 1;
	
}void DSU(){
	for(int i = 0; i < m; i++){
		if(Union(edge[i].ft, edge[i].sd) == 0){
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int test; cin >> test;
	while(test--)
	{
		inp();
		make_set();
		DSU();
	}
	return 0;
}

/*Code by: Tran Quang Huy*/
