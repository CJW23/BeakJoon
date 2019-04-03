#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

struct xyz {
	int x;
	int y;
	int z;
};
int a[102][102][102];
int vs[102][102][102];
int M, N, H, tmp;
queue<xyz> qu;
int rx[] = { -1, 1 ,0,0,0,0 };
int ry[] = { 0,0,-1,1,0,0 };
int rz[] = { 0,0,0,0,1,-1 };

int main() {
	cin >> M >> N >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> a[i][j][k];
				if (a[i][j][k] == 0)
					tmp = 1;
				if (a[i][j][k] == 1) {
					xyz tmp;
					tmp.z = i;
					tmp.y = j;
					tmp.x = k;
					vs[i][j][k] = 1;
					qu.push(tmp);
				}
				
			}
		}
	}
	if (tmp == 0)
	{
		cout << "0";
	}
	else 
	{
		int count1 = 0;
		while (1) {
			queue<xyz> q;
			while (!qu.empty()) {
				xyz tmp = qu.front();
				int x = tmp.x, y = tmp.y, z = tmp.z;
				qu.pop();
				for (int i = 0; i < 6; i++) {
					int mvz = z + rz[i],
						mvy = y + ry[i],
						mvx = x + rx[i],
						mvvs = vs[mvz][mvy][mvx],
						mva = a[mvz][mvy][mvx];

					if (mvz < H && mvz > -1 &&
						mvy < N && mvy > -1 &&
						mvx < M && mvx > -1) {
						if (mva == 0 && mvvs == 0) {

							a[mvz][mvy][mvx] = 1;
							vs[mvz][mvy][mvx] = 1;
							xyz a = { mvx, mvy, mvz };
							q.push(a);
						}
						else if (mva == -1 && mvvs == 0) {
							vs[mvz][mvy][mvx] = 1;
						}
					}
				}
			}
			qu = q;
			if (qu.empty())
				break;
			count1++;
		}

		int flag = 0;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < M; k++) {
					if (a[i][j][k] == 0) {
						flag = 1;
						break;
					}

				}
				if (flag == 1)
					break;
			}
			if (flag == 1)
				break;
		}
		if (flag == 1) {
			cout << "-1\n";
		}
		else {
			cout << count1 << "\n";
		}
		/*for (int i = 0; i < H; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < M; k++) {
					cout << vs[i][j][k];
				}
				 cout << "\n";
			}
			cout << "\n";
		}*/
	}
}