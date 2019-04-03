#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int N, M;
int n1, n2;
int fm[102][102];
int vs[102];
int dis[102];
int dist = 1;
queue<int> q;
int main() {
	cin >> N;
	cin >> n1 >> n2;
	cin >> M;

	for (int i = 0; i < M; i++) {
		int a,b;
		cin >> a >> b;
		fm[a][b] = 1;
		fm[b][a] = 1;
	}
	q.push(n1);

	while (!q.empty()) {
		int tmp;
		tmp = q.front();
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (fm[tmp][i] == 1 && vs[i] == 0) {
				vs[i] = 1;
				q.push(i);
				
				dis[i] = dis[tmp]+1;
			}
		}
	}
	if (vs[n2] == 1)
		cout << dis[n2];
	else
		cout << -1;
	
}