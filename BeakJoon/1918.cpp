#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;

stack<char> st;
int loc;

string sik1;
int main() {
	cin >> sik1;

	while (loc < sik1.size()) {
		if (sik1[loc] == '+' || sik1[loc] == '-') {
			if (st.empty() || (st.top() == '('))
				st.push(sik1[loc]);
			else if (st.top() == '*' || st.top() == '/') {
				cout << st.top();
				st.pop();
				if (!st.empty()) {
					if (st.top() == '+' || st.top() == '-') {
						cout << st.top();
						st.pop();
					}
				}
				st.push(sik1[loc]);
			}
			else if (st.top() == '+' || st.top() == '-') {
				cout << st.top();
				st.pop();
				st.push(sik1[loc]);
			}
		}
		else if (sik1[loc] == '*' || sik1[loc] == '/') {
			if (st.empty() || (st.top() == '('))
				st.push(sik1[loc]);
			else if (st.top() == '+' || st.top() == '-') {
				st.push(sik1[loc]);
			}
			else if (st.top() == '*' || st.top() == '/') {
				cout << st.top();
				st.pop();
				st.push(sik1[loc]);
			}
		}
		else if (sik1[loc] == '(')
			st.push(sik1[loc]);
		else if (sik1[loc] == ')') {
			while (st.top() != '(') {
				cout << st.top();
				st.pop();
			}
			st.pop();
		}
		else {
			cout << sik1[loc];
		}
		loc++;
	}
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
}