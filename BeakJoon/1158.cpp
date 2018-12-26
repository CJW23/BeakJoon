#include <iostream>
#include <queue>
using namespace std;

int main()
{
	queue<int> a;
	int N, M;
	int index = 0;
	int result[5001];
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		a.push(i);
	}
	while (!a.empty()) {
		int temp;
		for (int i = 0; i < M - 1; i++) {
			temp = a.front();
			a.pop();
			a.push(temp);
		}
		result[index] = a.front();
		index++;
		a.pop();
	}
	cout << "<" << result[0];
	for (int i = 1; i < index; i++) {
		cout << ", " << result[i];
	}
	cout << ">";
}