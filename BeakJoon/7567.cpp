#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;
string a;
int sum;
int main() {
	cin >> a;

	char tmp;
	for (int i = 0; i < a.size(); i++) {
		if (i == 0) {
			sum += 10;
			tmp = a[i];
			continue;
		}
		if (tmp != a[i]) {
			sum += 10;
		}
		else
			sum += 5;
		tmp = a[i];
	}
	cout << sum;
}