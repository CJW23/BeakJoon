#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct a {
	unsigned long S;
	unsigned long E;
}A;
bool cmp(const A &a, const A &b) {
	return a.E < b.E;
}
bool cmp2(const A &a, const A &b) {
	return a.S < b.S;
}
int main()
{
	vector<A> time;
	A temp;
	int N, count=0, point=0, i; 
	unsigned long Lt = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp.S;
		cin >> temp.E;
		time.push_back(temp);
	}
	sort(time.begin(), time.end(), cmp);

	for (i = 0; i < N; i++) {
		if (time[point].E == time[i].E) {
			continue;
		}
		else {
			partial_sort(time.begin() + point, time.begin() + i, time.begin() + i, cmp2);
			point = i;
		}
	}
	partial_sort(time.begin() + point, time.end(), time.end(), cmp2);
	for (int i = 0; i < N; i++) {
		if (Lt <= time[i].S) {
			Lt = time[i].E;
			count++;
		}
	}
	cout << count;
}