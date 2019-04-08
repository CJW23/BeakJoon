#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int N, M, K;
int T;
int ga[] = { -1,1,0,0 };
int se[] = { 0,0,-1,1 };
int bat[50][50];
int vs[50][50];
int count1;
int dfs(int x, int y) {
	if (vs[y][x] == 1)
		return 0;
	else if (vs[y][x] == 0) {
		vs[y][x] = 1;
	}
	for (int i = 0; i < 4; i++) {
		int tx = ga[i] + x, ty = se[i] + y;
		if (tx >= 0 && tx < M) {
			if (ty >= 0 && ty < N) {
				if(bat[ty][tx] == 1)
					dfs(tx, ty);
			}
		}
	}
	return 0;
}
int main() {
	cin >> T;
	for (int q = 0; q < T; q++) {
		cin >> M >> N >> K;
		for (int i = 0; i < K; i++) {
			int x, y;
			cin >> x >> y;
			bat[y][x] = 1;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (bat[i][j] == 1 && vs[i][j] == 0) {
					dfs(j, i);
					count1++;
				}
			}
		}
		cout << count1<<"\n";
		count1 = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				vs[i][j] = 0;
				bat[i][j] = 0;
			}
		}
	}
	
}