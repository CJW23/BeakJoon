#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;
string arr[6][6];
int vs, a;
string str;
vector<string> rst;
int rx[] = { -1,1,0,0 };
int ry[] = { 0,0,1,-1 };
void f(int y, int x) {
	//문자열이 완성 되었을때
	if (vs == 6) {	
		int flag = 0;
		for (int i = 0; i < rst.size(); i++) {
			if (rst[i] == str) {
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			rst.push_back(str);
		return;
	}


	str.append(arr[y][x]);
	string tmp = str;
	/*a++;
	cout << a << " " << tmp <<  "\n"; */
	for (int i = 0; i < 4; i++) {
		int tx = x + rx[i], ty = y + ry[i];
		if (tx < 0 || ty < 0 || tx >= 5 || ty >= 5) continue;
		vs++;
		f(ty, tx);
		str = tmp;
		vs--;
	}

	
}
int main() {

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			f(i, j);
			str.clear();
			vs = 0;
		}
	}

	cout << rst.size();
}