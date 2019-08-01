#include <iostream>

using namespace std;
int x[4] = {0, 0 ,1, -1};
int y[4] = {1, -1, 0, 0};
int N, M;
int originMap[65][65];
int wallMap[65][65];
int total;
int mem[65][65];

void f(int fx, int fy) {
	if (fx < 0 || fy < 0) {
		return;
	}
	if (fx > M || fy > N) {
		return;
	}
	if (wallMap[fy][fx] == 0)
		wallMap[fy][fx] = 2;
	for (int i = 0; i < 4; i++) {
		int tx = fx + x[i], ty = fy + y[i];
		if(wallMap[ty][tx] == 0)
			f(tx, ty);
	}
}

void countSafe() {
	int sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (wallMap[i][j] == 0)
				sum++;
		}
	}
	if (sum > total)
		total = sum;
}
void startVirous() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (mem[i][j] == 2)
				f(j, i);
		}
	}
}
void makeWall(int i, int j, int k, int z, int v, int u) {	//�� �����
	wallMap[i][j] = 1;
	wallMap[k][z] = 1;
	wallMap[v][u] = 1;
}
void makeOrigin() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			wallMap[i][j] = originMap[i][j];
			mem[i][j] = originMap[i][j];
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> originMap[i][j];
		}
	}
	
	for (int i = 0; i < N; i++) {	//ù��° �� y
		for (int j = 0; j < M; j++) {	//ù��° �� x
			if (originMap[i][j] == 1 || originMap[i][j] == 2) continue;	//ù��° �� ��ġ�� ���̳� ���̷��� ������
			for(int k=i; k < N; k++){	//�ι�° �� y
				for (int z = 0; z < M; z++) {	//�ι�° �� x
					if ((k == i && z == j) || originMap[k][z] == 1 || originMap[k][z] == 2) continue;	//�ι�° ���� ��,���̷��� �Ǵ� ù��° ���� ��ġ�� ���� ��
					for (int v = k; v < N; v++) {	//����° �� y
						for (int u = 0; u < M; u++) {	//����° �� x
							if (originMap[v][u] == 1 || originMap[v][u] == 2) continue;	//����° �� ��,���̷���
							if ((v == i && u == j) || (v == k && u == z)) continue;		//ù��° �� �Ǵ� �ι�° ���� ���� ��
							//printf("(%d,%d) (%d,%d) (%d,%d)\n ", i, j, k, z, v, u);
							makeOrigin();
							makeWall(i, j, k, z, v, u);
							startVirous();
							countSafe();
						}
					}
					
				}
			}	
		}
	}
	cout << total;
}
