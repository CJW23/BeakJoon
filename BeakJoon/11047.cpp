#include <iostream>

using namespace std;
//N = ������ ���� ����, K = ������ ��
int main()
{
	int coin[10];
	int N, K, count=0, temp;
	cin >> N >> K;
	for (int i = N-1; i >= 0; i--) {
		cin >> coin[i];
	}
	temp = K;
	for (int i = 0; i < N; i++) {
		if (coin[i] <= temp) {
			count += temp / coin[i];
			temp = temp % coin[i];
		}
	}
	cout << count;
}