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

	if (vs[milk][y][x] != -1)	//�̹� �غ� �����̶��
		return vs[milk][y][x];

	if (x == N || y == N) {   //�� �������� ������
		return 0;
	}

	if (milk == arr[y][x]) { //������ �ִ� ������ ���
		if (milk == 0 || milk == 1)   //���� ���� ����
			chMilk = milk + 1;
		else
			chMilk = 0;

		eat = max({ f(milk, x + 1, y), f(milk, x, y + 1), 1 + f(chMilk, x + 1, y), 1 + f(chMilk, x, y + 1) });	//������ �ȸ��� ���� ���� ���� ����
		vs[milk][y][x] = eat;   //���� ���� ����
	}
	else{	//���� �� �ִ� ������ �ƴ϶��
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