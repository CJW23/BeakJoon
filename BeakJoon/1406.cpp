//#include <iostream>
//#include <stack>
//#include <string>
//using namespace std;
//
//int main()
//{
//	stack<char> L;
//	stack<char> R;
//	string seq;
//
//	cin >> seq;
//
//	for (int i = 0; i < seq.size(); i++)
//		L.push(seq[i]);
//
//
//	int num;
//	string a;
//	cin >> num;
//
//	for (int i = 0; i < num; i++)
//	{
//		cin >> a;
//		if (a[0] == 'P') {
//			char temp;
//			cin >> temp;
//			L.push(temp);
//		}
//		else if (a[0] == 'L') {
//			if (!L.empty()) {
//				char temp = L.top();
//				L.pop();
//				R.push(temp);
//			}
//		}
//		else if (a[0] == 'D') {
//			if (!R.empty()) {
//				char temp = R.top();
//				R.pop();
//				L.push(temp);
//			}
//		}
//		else if (a[0] == 'B') {
//			if (!L.empty()) {
//				L.pop();
//			}
//		}
//	}
//	
//	while (!L.empty())
//	{
//		R.push(L.top());
//		L.pop();
//	}
//	while (!R.empty())
//	{
//		cout << R.top();
//		R.pop();
//	}
//	
//}