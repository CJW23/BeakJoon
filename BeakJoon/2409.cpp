#include <iostream>
#include <algorithm>
using namespace std;

int N, stair[305], save1[1000][1000], rst;

int f(int fst, int secd) {
	if (secd == N) {
		return stair[secd];
	}
	else if (fst == N - 2 && secd == N - 1) {
		return -300000000;
	}
	if (save1[fst][secd] != -1)
		return save1[fst][secd];

	if (secd - fst == 1 && secd != 1 && fst != 0) {
		int temp = f(secd, secd + 2);
		save1[secd][secd + 2] = temp;
		return stair[secd] + temp;
	}
	else if ((fst == 0 && secd == 1) || (secd - fst == 2) || (fst == 0 && secd == 0)) {
		int temp1 = f(secd, secd + 1);
		int temp2 = f(secd, secd + 2);
		save1[secd][secd + 1] = temp1;
		save1[secd][secd + 2] = temp2;
		if (temp1 >= temp2) {
			return stair[secd] + temp1;
		}
		else
			return stair[secd] + temp2;
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &stair[i]);
	}
	for (int i = 0; i < 305; i++) {
		for (int j = 0; j < 305; j++) {
			save1[i][j] = -1;
		}
	}
	if (N == 1) {
		printf("%d", stair[1]);
	}
	else if (N == 2) {
		printf("%d", stair[1] + stair[2]);
	}
	else {
		rst = f(0, 0);
		printf("%d", rst);
	}
}
