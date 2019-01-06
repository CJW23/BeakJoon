#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> count1;

int f(int x) {
	int result;
	if (x == 1)
		return 0;
	if (count1[x] != -1)
		return count1[x];

	result = f(x - 1) + 1;
	if (x % 2 == 0)
		result = min(f(x / 2) + 1, result);
	if (x % 3 == 0)
		result = min(f(x / 3) + 1, result);

	count1[x] = result;
	return result;
}

int main() {
	int X;
	int Y;
	cin >> X;
	count1.resize(X+1, -1);
	Y = f(X);
	cout << Y;
}

