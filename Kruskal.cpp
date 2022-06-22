#include <bits/stdc++.h >
using namespace std;
struct edge{
	int u, v, w;
};
bool cmp(edge a, edge b)
{
	return a.w < b.w;
}
vector <edge> canh;
int n, m;
const int maxn = 1001; 
int parent[maxn], size[maxn];

void make_set()
{
	for(int i = 1; i <= n; i++)
	{
		parent[i] = i;
		size[i] = i;
	}
}
int find(int v)
{
	if(v == parent[v])
		return v;
	return parent[v] = find(parent[v]);
}
bool Union(int a, int b)
{
	a = find(a);
	b = find(b);
	if(a == b) return false;// khong the gop a, b
	if(size[a] < size[b]) swap(a, b);
	parent[b] = a;
	size[a] += size[b];
}
void inp()
{
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int x, y, z; cin >> x >> y >> z;
		canh.push_back({x, y, z});
		// edge e = edge({x, y, z}); canh.push_back(e);
		
	}
}
void kruskal()
{
	// tao cay khung cuc tieu rong
	vector <edge> mst;
	int d = 0;
	//sort danh dach canh theo trong so tang dan
	sort(canh.begin(), canh.end(), cmp);
	// buoc 3: lap
	for(int i = 0; i < m; i++)
	{
		if(mst.size() == n-1) break;
		edge e = canh[i];
		if(Union(e.u, e.v)) // neu canh u, v khong tao thanh chu trinh
		{
			mst.push_back(e);
			d += e.w;
		}
	}
	// tra ve ket qua
	if(mst.size() != n-1)
		cout <<"Do thi khong lien thong!\n";
	else
	{
		cout << "MST: " << d << endl;
		for(auto it : mst)
			cout << it.u << " " << it.v << " " << it.w << endl;
	}
}
//6 9
//1 2 12
//1 3 4
//2 3 1
//2 4 5
//2 5 3 
//3 5 2
//4 5 3
//4 6 11
//5 6 8

int main()
{
	inp();
	make_set();
	kruskal();
	return 0;
}
/*Code by: Tran Quang Huy*/