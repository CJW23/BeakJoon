#include <iostream>

using namespace std;

int main() {
	int n;
	int flag = 0; 
	int sum=0;
	int i;
	cin >> n;
	
	for (i = 0; i < n; i++) {
		int div;
		div = i;
		sum += div;
		while (div > 10) {
			sum += (div % 10);
			div = div / 10;
		}
		sum += div;

		if (sum == n) {
			flag = 1;
			break;
		}
		else
			sum = 0;
	}
	if (flag == 1)
		cout << i;
	else
		cout << 0;
	
	
}