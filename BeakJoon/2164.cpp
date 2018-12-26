#include <iostream>
#include <queue>
using namespace std;

int main()
{
	queue<int> a;
	int num;

	cin >> num;
	for (int i = 1; i <= num; i++) {
		a.push(i);
	}

	bool flag = true;
	while (a.size() > 1) {
		if (flag == true) {
			a.pop();
			flag = false;
		}
		else
		{
			flag = true;
			int temp = a.front();
			a.pop();
			a.push(temp);
		}
	}
	cout << a.front();
}