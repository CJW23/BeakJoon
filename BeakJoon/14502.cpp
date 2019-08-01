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
void makeWall(int i, int j, int k, int z, int v, int u) {	//벽 세우기
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
	
	for (int i = 0; i < N; i++) {	//첫번째 점 y
		for (int j = 0; j < M; j++) {	//첫번째 점 x
			if (originMap[i][j] == 1 || originMap[i][j] == 2) continue;	//첫번째 점 위치에 벽이나 바이러스 있을시
			for(int k=i; k < N; k++){	//두번째 점 y
				for (int z = 0; z < M; z++) {	//두번째 점 x
					if ((k == i && z == j) || originMap[k][z] == 1 || originMap[k][z] == 2) continue;	//두번째 점에 벽,바이러스 또는 첫번째 점과 위치가 같을 때
					for (int v = k; v < N; v++) {	//세번째 점 y
						for (int u = 0; u < M; u++) {	//세번째 점 x
							if (originMap[v][u] == 1 || originMap[v][u] == 2) continue;	//세번째 점 벽,바이러스
							if ((v == i && u == j) || (v == k && u == z)) continue;		//첫번째 점 또는 두번째 점과 같을 때
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
