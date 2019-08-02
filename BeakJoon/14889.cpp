#include <iostream>
#include <vector>
using namespace std;

int map[22][22];
int N;
int cnt;

int rst = 123456789;	//큰값 지정
bool vs[22];
void teamScore() {
	vector<int> start, link;
	int ssum = 0, lsum = 0;
	int minus;
	//start팀 link팀 분리
	for (int i = 0; i < N; i++) {
		if (vs[i]) {
			start.push_back(i);
		}
		else
			link.push_back(i);
	}

	//점수 합산
	for (int i = 0; i < start.size(); i++) {
		for (int j = 0; j < start.size(); j++) {
			ssum += map[start[i]][start[j]];
		}
	}
	for (int i = 0; i < link.size(); i++) {
		for (int j = 0; j < link.size(); j++) {
			lsum += map[link[i]][link[j]];
		}
	}

	//점수 차
	if (ssum > lsum)
		minus = ssum - lsum;
	else
		minus = lsum - ssum;

	if (rst > minus)
		rst = minus;
}
void f(int n) {
	cnt++;
	vs[n] = true;
	if (cnt == N / 2)
		teamScore();
	else {
		for (int i = n+1; i < N; i++) { 
			if(!vs[i])
				f(i);
		}
	}
	vs[n] = false;
	cnt--;
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	f(0);
	cout << rst << endl;
	
}
