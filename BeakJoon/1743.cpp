#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
int N, M, K;
int arr[101][101];
int vs[101][101];
int rst, tmprst;
int xx[] = { -1,1,0,0 };
int yy[] = { 0,0,-1,1 };

int f(int y, int x) {
	if (vs[y][x] == 1)
		return 0;
	else {
		vs[y][x] = 1;
		tmprst++;
	}

	int tmp = 0;
	for (int i = 0; i < 4; i++) {
		int yv = yy[i] + y, xv = xx[i] + x;
		if(yv >= 0 && xv >= 0)
			if(yv <= N && xv <=M)
				if(arr[yv][xv] == 1)
					f(yy[i] + y, xx[i] + x);
	}
	return 0;
}
int main() {
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (arr[i][j] == 1) {
				f(i, j);
				if (tmprst > rst) {
					rst = tmprst;
					tmprst = 0;
				}
				else
					tmprst = 0;
			}
		}
	}
	cout << rst;
}