#include <iostream>
#include <algorithm>
#include <stack>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

char alp[30];
int alpcnt;

int main() {
	int num, grpcnt=0;
	string word[101];
	cin >> num;

	for (int i = 0; i < num; i++) 
		cin >> word[i];

	for (int p = 0; p < num; p++) {
		int flag = 0;

		char temp = word[p][0];
		alp[alpcnt] = temp;
		alpcnt++;

		for (int i = 1; i < word[p].size(); i++) {
			if (temp == word[p][i])
				continue;
			temp = word[p][i];
			alp[alpcnt] = temp;
			alpcnt++;
		}

		int flag1 = 0;
		for (int i = 0; i < alpcnt; i++) {	//그룹단어 판별
			for (int j = i + 1; j < alpcnt; j++) {
				if (alp[i] == alp[j]) {	//그룹 단어
					flag1 = 1;
					break;
				}
			}
			if (flag1 == 1)	//그룹 단어일 경우
				break;
		}
		if (flag1 == 0)
			grpcnt++;
		alpcnt = 0;
	}
	cout << grpcnt;
}