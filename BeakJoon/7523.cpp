#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int num;
	long long n, m;
	vector<pair<long long, long long>> arr;

	cin >> num;

	for (int i = 0; i < num; i++) {
		int a, b;
		cin >> a >> b;
		arr.push_back(make_pair(a, b));
	}
	for (int i = 0; i < num; i++) {
		long long a, b, sum, cnt, rst;
		a = arr[i].first;
		b = arr[i].second;
		sum = a + b;
		if (a >= 0) {
			cnt = b - a + 1;
			rst = (sum * cnt)/2;
		}
		else {
			cnt = (-1 * a) + b + 1;
			rst = (sum*cnt) / 2;
		}
		cout << "Scenario #"<<i+1<<":\n"<<rst<<"\n\n";
	}
}