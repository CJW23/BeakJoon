#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int N, j = 0;
string a;
int main() {
	getline(cin, a);

	for (int i = 0; i < a.length(); i++) {
		printf("%c", a.at(i));
		j++;
		if (j == 10)
		{
			j = 0;
			printf("\n");
		}
	}
}