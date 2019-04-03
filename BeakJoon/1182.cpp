#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int N, S;
int arr[22];
int res;
vector<int> a[21];
int visit[21];
void dfs(int sum, int p) {
	if (p == N) {
		if (sum == S) {
			res++;
		}
		return;
	}
	dfs(sum + arr[p], p + 1);
	dfs(sum, p + 1);
}
int main() {
	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	dfs(0, 0);
	if (S == 0)
		res -= 1;
	cout << res;
}
