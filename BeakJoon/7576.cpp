#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
vector<int> a;
int c[1003];
int N, M, count1;
int arr[1003][1003];
int dx[] = { 0, -1, 1 ,0 };
int dy[] = { -1, 0, 0, 1 };
int visit[1003][1003];
queue<pair<int,int>> qu;
int main() {
	//N까지 M개의 중복되지 않는 수열
	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				visit[i][j] = 1;
				qu.push(make_pair(i, j));
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0)
				cnt++;
		}
	}
	if (cnt == 0) {
		cout << "0";
		return 0;
	}
	
	while (1) {
		queue<pair<int, int>> qu2;
		while (!qu.empty()) {
			pair<int, int> a = qu.front();
			qu.pop();
			for (int i = 0; i < 4; i++) {
				int y = a.first + dx[i], x = a.second + dy[i];
				if (x > -1 && y > -1 && x < M && y < N) {
					if (arr[y][x] == 0 &&
						visit[y][x] == 0) {
						qu2.push(make_pair(y, x));
						visit[y][x] = 1;
					}
					else if (arr[y][x] == -1) {
						visit[y][x] = 1;
					}
				}
			}
		}
		qu = qu2;
		if (qu.empty())
			break;
		count1++;
	}
	int temp = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visit[i][j] == 0) {
				if (arr[i][j] != -1){
					temp = 1;
					break;
				}
			}
		}
		if (temp == 1)
			break;
	}
	
	if (temp == 1)
		cout << "-1";
	else
		cout << count1;
}