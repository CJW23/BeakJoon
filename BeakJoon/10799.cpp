#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a;
	int left = 0, right = 0;
	int total = 0;
	bool b = false;
	cin >> a;

	for (int i = 0; i < a.size(); i++) {
		if (a[i] == '(') {
			left++;
			b = false;
		}
		else if (a[i] == ')' && !b) {
			left--;
			total += left;
			b = true;
		}
		else if (a[i] == ')' && b) {
			total++;
			left--;
		}
	}
	cout << total << endl;
}