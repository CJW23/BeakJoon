#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
int N[100005];
vector<char> ans;
int count1;
int stacknum = 1;
stack<int> list;
int main() {
	int a, flag = 0;
	scanf("%d", &a);
	for (int i = 0; i < a; i++) {
		scanf("%d", &N[i]);
	}
	//stacknum = 스택에 쌓을 숫자
	//list = 1~n까지 들어있는 스택

	for (int i = 0; i < a; i++) {
		if (list.empty()) {
			list.push(stacknum);
			ans.push_back('+');
			stacknum++;
			while (list.top() < N[i]) {
				ans.push_back('+');
				list.push(stacknum);
				stacknum++;
			}
			ans.push_back('-');
			list.pop();
		}
		else if (list.top() < N[i]) {
			while (list.top() < N[i]) {
				ans.push_back('+');
				list.push(stacknum);
				stacknum++;
			}
			ans.push_back('-');
			list.pop();
		}
		else if (list.top() == N[i]) {
			ans.push_back('-');
			list.pop();
		}
		else if (list.top() != N[i]) {
			printf("NO");
			flag = 1;
			break;
		}
	}
	if (flag == 0) {
		for (int i = 0; i < ans.size(); i++) {
			printf("%c\n", ans[i]);
		}
	}
}