#include <iostream>

using namespace std;
int N, count1 = 0;
int main() {
	scanf("%d", &N);
	if (N < 100) {	//2자리 이하면 모두 등차수열
		printf("%d", N);
	}
	else if (N <= 110) { //110까지는 등차수열 99개
		printf("99");
	}
	else if (N == 1000) {
		printf("144");
	}
	else {
		count1 = 99;
		for (int i = 111; i <= N; i++) {
			int temp = i, store[3], j = 0;
			while (temp >= 10) {
				store[j] = temp % 10;
				temp /= 10;
				j++;
				if (temp < 10) {	//temp가 첫째자리 수일 때
					store[j] = temp;
					if ((store[1] - store[0]) == (store[2] - store[1])) {
						count1++;
					}
				}
			}
		}
		printf("%d", count1);
	}
	
}