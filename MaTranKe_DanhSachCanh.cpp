#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1001][1001];
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
			cin >> a[i][j];
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(a[i][j] && i < j)
				cout << i << " " << j << endl;
		}
	}
	return 0;
}

