#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
int N, M;
char arr[50][50];
int rst = 100;
int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i <= N- 8; i++) {//탐색할 체스판 영역
		for (int j = 0; j <= M - 8; j++) {
			for (int q = 0; q < 2; q++) {	//가장자리 검은색, 흰색 둘다
				int count1 = 0;
				char color;

				if (q == 0)	//q가 0일때 가장자리가 W로 시작
					color = 'W';
				else		//1일 때 가장자리가 B로 시작
					color = 'B';

				for (int k = i; k < i + 8; k++) {	//바꿔야하는 색깔 수 count
					for (int z = j; z < j + 8; z++) {
						if (arr[k][z] != color)
							count1++;
						if (color == 'W' && z != j+7)
							color = 'B';
						else  if(color == 'B' && z != j + 7)
							color = 'W';
					}
				}
				if (rst > count1)
					rst = count1;
			}
		}
	}
	cout << rst;
}
