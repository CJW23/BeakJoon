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

	for (int i = 0; i <= N- 8; i++) {//Ž���� ü���� ����
		for (int j = 0; j <= M - 8; j++) {
			for (int q = 0; q < 2; q++) {	//�����ڸ� ������, ��� �Ѵ�
				int count1 = 0;
				char color;

				if (q == 0)	//q�� 0�϶� �����ڸ��� W�� ����
					color = 'W';
				else		//1�� �� �����ڸ��� B�� ����
					color = 'B';

				for (int k = i; k < i + 8; k++) {	//�ٲ���ϴ� ���� �� count
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
