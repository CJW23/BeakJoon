#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> v;
	int height;
	int sum=0;
	int theif1, theif2;
	for (int i = 0; i < 9; i++) {
		cin >> height;
		sum += height;
		v.push_back(height);
	}
	
	sort(v.begin(), v.end());

	for (int i = 0; i < 8; i++) {
		for (int j = i+1; j < 9; j++) {
			if((sum - v[i] - v[j]) == 100){
				theif1 = v[i];
				theif2 = v[j];
			}
		}
	}

	for (int i = 0; i < 9; i++) {
		if (v[i] != theif1 && v[i] != theif2) {
			cout << v[i] << endl;
		}
	}
	
}