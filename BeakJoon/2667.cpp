#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int N;
int arr[26][26];
int comcnt;
int cnt;
vector<int> cntrst;
int vs[26][26];
int locx[] = { 0,0,-1,1 };
int locy[] = { -1,1,0,0 };

int f(int x, int y);
int f(int x, int y) {
	if (vs[y][x] == 1)
		return 0;
	else {
		vs[y][x] = 1;
		cnt++;
	}

	for (int i = 0; i < 4; i++) {
		int xx = x + locx[i];
		int yy = y + locy[i];
		if (xx >= 0 && yy >= 0) {
			if (xx < N && yy < N) {
				if (arr[yy][xx] == 1)
					f(xx, yy);
			}
		}
	}
	return 0;
}
int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 1 && vs[i][j] == 0) {
				f(j, i);
				cntrst.push_back(cnt);
				comcnt++;
			}
			cnt = 0;
		}
	}
	cout << comcnt<<"\n";
	sort(cntrst.begin(), cntrst.end());
	for (int i = 0; i < cntrst.size(); i++) {
		cout << cntrst[i] << "\n";
	}
}