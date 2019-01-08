#include <iostream>
#include <vector>

using namespace std;
int N;
long long count1;
long long dp[95][2];

long long f(int N, int st) {
	long long result = 0;
	if (N == 0)
		return 1;
	if (dp[N][st] != -1)
		return dp[N][st];
	if (st == 0) {
		result += f(N - 1, 0);
		result += f(N - 1, 1);
		dp[N][st] = result;
	}
	else if(st == 1){
		result += f(N - 1, 0);
		dp[N][st] = result;
	}

	return result;
}
int main() {
	cin >> N;
	for (int i = 0; i < 95; i++) {
		for (int j = 0; j < 2; j++) {
			dp[i][j] = -1;
		}
	}
	if (N == 1 || N == 2)
		count1 = 1;
	else
		count1 = f(N - 2, 0);
	cout << count1;
}