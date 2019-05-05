#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;
char arr[101][101];
char arr1[101][101];
int px[] = { 0,0,-1,1 };
int py[] = { -1,1,0,0 };
int vs[101][101];
int vs1[101][101];
int n,b,g,r, b1, g1, r1;
int f(int x, int y, char color) {
	if (vs[y][x] == 1 || arr[y][x] != color)
		return 0;
	if (arr[y][x] == color) {
		vs[y][x] = 1;
	}
	for (int i = 0; i < 4; i++) {
		int xx = x + px[i];
		int yy = y + py[i];
		if (xx >= 0 && xx < n) {
			if (yy >= 0 && yy < n) {
				f(xx, yy, color);
			}
		}
	}
}
int f1(int x, int y, char color) {
	if (vs1[y][x] == 1 || arr1[y][x] != color)
		return 0;
	if (arr1[y][x] == color) {
		vs1[y][x] = 1;
	}
	for (int i = 0; i < 4; i++) {
		int xx = x + px[i];
		int yy = y + py[i];
		if (xx >= 0 && xx < n) {
			if (yy >= 0 && yy < n) {
				f1(xx, yy, color);
			}
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char tmp;
			cin >> tmp;
			arr[i][j] = tmp;
			if (tmp == 'R')
				arr1[i][j] = 'G';
			else
				arr1[i][j] = tmp;
			
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 'B' && vs[i][j] == 0) {
				f(j, i, 'B');
				b++;
			}
			else if (arr[i][j] == 'G' && vs[i][j] == 0) {
				f(j, i, 'G');
				g++;
			}
			else if (arr[i][j] == 'R' && vs[i][j] == 0) {
				f(j, i, 'R');
				r++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr1[i][j] == 'B' && vs1[i][j] == 0) {
				f1(j, i, 'B');
				b1++;
			}
			else if (arr1[i][j] == 'G' && vs1[i][j] == 0) {
				f1(j, i, 'G');
				g1++;
			}
		}
	}
	cout << b + g + r << " " << b1 + g1;
}