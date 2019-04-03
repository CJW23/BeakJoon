#include <iostream>
#include <algorithm>
#include <stack>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

string a;
char alp[30];
int cnt[30];
int alpcnt;
int main() {
	int i;
	cin >> a;

	for (i = 0; i < a.size(); i++) {
		a[i] = toupper(a[i]);
	}

	for (i = 0; i < a.size(); i++) {
		int flag = 0;
		for (int j = 0; j < alpcnt; j++) {
			if (alp[j] == a[i]) {
				cnt[j]++;
				flag = 1;
				break;
			}
		}
		if (flag == 0) {	//일치하는 알파벳 없으면
			alp[alpcnt] = a[i];	//알파벳 등록
			cnt[alpcnt]++;
			alpcnt++;
		}
	}

	int max = 0;
	int flag = 0;
	for (i = 1; i < 30; i++) {
		if (cnt[max] < cnt[i]) {
			max = i;
			flag = 0;
		}
		else if (cnt[max] == cnt[i]) {
			flag = 1;
		}
	}
	if (flag == 0) {
		cout << alp[max];
	}
	else {
		cout << "?";
	}
}