#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int list[105];
int count1;
int concent[105][2];
int instance[105];
int useconcent;

int main() {
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		cin >> list[i];
	}
	for (int i = 0; i < K; i++) {
		int num = 1, flag = 0;
		for (int j = i+1; j < K; j++) {
			if (list[i] == list[j]) {
				instance[i] = num;
				flag = 1;
				break;
			}
			else
				num++;
		}
		if (flag == 0)		//처음이자 마지막
			instance[i] = 1000;
	}

	for (int i = 0; i < K; i++) {
		for (int q = 0; q < useconcent; q++) {
			instance[concent[q][1]] -= 1;
		}
		if (useconcent == 0) {	//콘센트가 하나도 없을 때
			concent[0][0] = list[i];	//번호 입력
			concent[0][1] = i;			//인덱스 입력
			useconcent++;		//사용 콘센트 증가
		}
		else if(useconcent < N){		//콘센트가 남았을 때
			int flag = 0;
			for (int j = 0; j < useconcent; j++) {	//사용중인 콘센트까지
				if (list[i] == concent[j][0]) {		//같은 아이템인지 확인
					concent[j][0] = list[i];
					concent[j][1] = i;
					flag = 1;
					break;
				}
			}
			if (flag == 0) {		//없으면 concent 추가
				concent[useconcent][0] = list[i];
				concent[useconcent][1] = i;
				useconcent++;
			}
		}
		else {		//콘센트가 안남았을 때
			int flag1 = 0;
			for (int j = 0; j < N; j++) {	//같은 아이템 있는 확인
				if (list[i] == concent[j][0]) {
					concent[j][0] = list[i];
					concent[j][1] = i;
					flag1 = 1;
					break;
				}
			}
			//list index = instance index
			if (flag1 == 0) {	//콘센트 빼야할 경우
				int result = 0;
				int index;
				for (int j = 0; j < N; j++) {
					if (result <= instance[concent[j][1]]){
						result = instance[concent[j][1]];
						index = j;
					}
				}
				concent[index][0] = list[i];
				concent[index][1] = i;
				count1++;
			}
		}
	}
	cout << count1;
}