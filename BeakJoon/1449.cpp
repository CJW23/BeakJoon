//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int main() {
//	int N, L;
//	int h[1005];
//	int count=1;
//	int tape = 0;
//	cin >> N >> L;
//	
//	for (int i = 0; i < N; i++)
//		cin >> h[i];
//	sort(h, h + N);
//	tape = h[0] + L;
//	for (int i = 1; i < N; i++) {
//		if (tape <= h[i]) {
//			tape = h[i] + L;
//			count++;
//		}
//	}
//	cout << count <<"\n";
//}