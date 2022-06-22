#include <bits/stdc++.h>
using namespace std;
vector <pair<int, int>> adj;
int main()
{
	int n; cin >> n;
	cin.ignore();
	for(int i = 1; i <= n; i++)
	{
		string s, num;
		getline(cin, s);
		stringstream ss(s);
		while(ss >> num)
		{
			int t = stoi(num);
			if(i < t)
				adj.push_back({i, t});
		}
	}
	for(auto x : adj)
		cout << x.first << " " << x.second << endl;
	return 0;
}

