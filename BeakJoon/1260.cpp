#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
vector<int> a[1003];
int c[1003];
void dfs(int x) {
	if (c[x] == 1) return;
	c[x] = 1;
	cout << x << " ";
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		dfs(y);
	}
}
void bfs(int x) {
	queue<int> qu;
	qu.push(x);
	c[x] = 1;

	while (!qu.empty()) {
		int tmp = qu.front();
		qu.pop();
		cout << tmp << " ";
		for (int i = 0; i < a[tmp].size(); i++) {
			if (c[a[tmp][i]] != 1) {
				qu.push(a[tmp][i]);
				c[a[tmp][i]] = 1;
			}
		}
		
	}
}
int main() {
	int N, M, V;
	//N = 정점 M = 간선 V = 정점 번호
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		int a1, b2;
		cin >> a1 >> b2;
		a[a1].push_back(b2);
		a[b2].push_back(a1);
	}	
	for (int i = 1; i <= 1000; i++) {
		sort(a[i].begin(), a[i].end());
	}
	dfs(V);
	cout << "\n";
	for (int i = 0; i <= 1000; i++) {
		c[i] = 0;
	}
	bfs(V);
}