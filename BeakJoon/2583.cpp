#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int N, M, K;
int arr[101][101];
int cnt;
int sum;
vector<int> cntrst;
int vs[101][101];
int locx[] = { 0,0,-1,1 };
int locy[] = { -1,1,0,0 };

int f(int x, int y) {
	if (vs[y][x] == 1)
		return 0;
	else {
		vs[y][x] = 1;
		cnt++;
	}
	for (int i = 0; i < 4; i++) {
		int xx = x + locx[i], yy = y + locy[i];
		if (xx >= 0 && yy >= 0) {
			if (xx < N && yy < M) {
				if(arr[yy][xx] == 0 && vs[yy][xx] == 0)
					f(xx, yy);
			}
		}
	}
}
int main() 
{
	cin >> M >> N >> K;
	
	for (int i = 0; i < K; i++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = y1; i < y2; i++) {
			for (int j = x1; j < x2; j++) {
				arr[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (vs[i][j] == 0 && arr[i][j] == 0) {
				f(j, i);
				sum++;
				cntrst.push_back(cnt);
			}
			cnt = 0;
		}
	}

	sort(cntrst.begin(), cntrst.end());
	/*for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cout << vs[i][j] << " ";
		}
		cout << "\n";
	}*/
	cout << sum << "\n";
	for (int i = 0; i < cntrst.size(); i++) {
		cout << cntrst[i] << " ";
	}
}