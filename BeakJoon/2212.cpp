#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
int N, K;
vector<int> sen;
vector<int> dis;
int main() {
	cin >> N;
	cin >> K;

	if (N <= K)
		cout << 0;
	else {
		for (int i = 0; i < N; i++) {
			int tmp;
			cin >> tmp;
			sen.push_back(tmp);
		}

		sort(sen.begin(), sen.end());

		for (int i = 1; i < sen.size(); i++) {
			int tmp;
			tmp = sen[i] - sen[i - 1];
			dis.push_back(tmp);
		}
		sort(dis.begin(), dis.end());

		int sum = 0;
		for (int i = 0; i < dis.size() - (K - 1); i++) {
			sum += dis[i];
		}
		cout << sum;
	}
}