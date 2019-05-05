#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int L, C;
vector<char> ch;
int moem, jaem;
int cnt;
vector<char> rst;
int f(int x) {
	if (cnt == L) {
		if (moem >= 1 && jaem >= 2) {
			for (int i = 0; i < L; i++) {
				cout << rst[i];
			}
			cout << "\n";
		}
		return 0;
	}
	if (x < C) {
		rst.push_back(ch[x]);
		if (ch[x] == 'a' || ch[x] == 'e' || ch[x] == 'i' || ch[x] == 'o' || ch[x] == 'u')
			moem++;
		else
			jaem++;

		cnt++;
		f(x + 1);

		rst.pop_back();
		cnt--;
		if (ch[x] == 'a' || ch[x] == 'e' || ch[x] == 'i' || ch[x] == 'o' || ch[x] == 'u')
			moem--;
		else
			jaem--;


		f(x + 1);

		
	}
}
int main() {
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		char a;
		cin >> a;
		ch.push_back(a);
	}
	sort(ch.begin(), ch.end());

	f(0);


}