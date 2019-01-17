#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> a;
int main() {
	scanf("%d", &N);
	a.assign(N, 0);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	sort(a.begin(), a.end());

	for (int i = 0; i < N; i++) {
		printf("%d\n", a[i]);
	}
}