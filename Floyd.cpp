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
const int INF = 1e9+10;
int n, m, a[101][101], d[101][101];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y, w; cin >> x >> y >> w;
		a[x][y] = a[y][x] = w;
	}
	
	// Floyd
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i != j && a[i][j] == 0)
				d[i][j] = INF;
			else d[i][j] = a[i][j];
		}
	}
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(d[i][j] > d[i][k] + d[k][j]){
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}
	int q; cin >> q;
	while(q--){
		int x, y; cin >> x >> y;
		cout << d[x][y] << endl;
	}
	return 0;
}

/*Code by: Tran Quang Huy*/
