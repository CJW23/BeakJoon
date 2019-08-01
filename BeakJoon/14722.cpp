#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;
int arr[1001][1001];
int vs[3][1001][1001];
int N;
int rst;

int f(int milk, int x, int y) {
	int chMilk = 0;
	int eat = 0;

	if (vs[milk][y][x] != -1)	//이미 해본 과정이라면
		return vs[milk][y][x];

	if (x == N || y == N) {   //끝 지점까지 왔으면
		return 0;
	}

	if (milk == arr[y][x]) { //먹을수 있는 우유인 경우
		if (milk == 0 || milk == 1)   //먹을 우유 결정
			chMilk = milk + 1;
		else
			chMilk = 0;

		eat = max({ f(milk, x + 1, y), f(milk, x, y + 1), 1 + f(chMilk, x + 1, y), 1 + f(chMilk, x, y + 1) });	//우유를 안먹을 수도 먹을 수도 있음
		vs[milk][y][x] = eat;   //먹은 우유 저장
	}
	else{	//먹을 수 있는 우유가 아니라면
		eat = max({ f(milk, x + 1, y), f(milk, x, y + 1) });
		vs[milk][y][x] = eat;
	}
	
	return eat;
}

int main() {
	cin >> N;
	for (int a = 0; a < 3; a++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				vs[a][i][j] = -1;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	
	rst = f(0, 0, 0);
	cout << rst;
}