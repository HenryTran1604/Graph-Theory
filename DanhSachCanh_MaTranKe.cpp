#include <bits/stdc++.h>
using namespace std;
// chuyen tu danh sach canh sang ma tran ke
int main()
{
	int n, m; cin >> n >> m; // n: so dinh, cnt: so canh
	int a[n+1][n+1] =  {};
	while(m --)
	{
		int x, y; cin >> x >> y;
		a[x][y] = a[y][x] = 1;
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
			cout << a[i][j] << " ";
		cout <<"\n";
	}
	return 0;
}
