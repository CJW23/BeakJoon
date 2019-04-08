#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
int N, M;
vector<int> grp[1002];
int vs[1002];
int count1;
int f(int x) {
	if (vs[x] == 1)
		return 0;
	else
		vs[x] = 1;
	for (int i = 0; i < grp[x].size(); i++) {
		f(grp[x][i]);
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		grp[a].push_back(b);
		grp[b].push_back(a);
	}
	
	for (int i = 1; i <= N; i++) {
		if (vs[i] == 0) {
			f(i);
			count1++;
		}
	}
	if (N == 1)
		cout << "1";
	else
		cout << count1;
}