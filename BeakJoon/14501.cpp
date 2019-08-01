#include <iostream>

using namespace std;

typedef struct sche {
	int day;
	int money;
}sche;

sche sc[1000];
int N;
int total;

void f(int today, int sum) {
	if (today <= N) {
		if (today + sc[today].day - 1 > N) {	//다음 일이 퇴사날을 넘으면
			if (total < sum) {
				total = sum;
			}
		}
		else {
			f(today + sc[today].day, sum + sc[today].money);	//그날 일 처리
		}
	}
	else {
		if (total < sum) {
			total = sum;
		}
	}
	if (today + 1 <= N) {
		f(today + 1, sum);//그날 일 처리 안하고 다음날
	}
}
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> sc[i].day >> sc[i].money;
	}
	for (int i = 1; i <= N; i++) {
		f(i, 0);
	}
	cout << total;
	
}