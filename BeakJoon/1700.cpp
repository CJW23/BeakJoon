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
		if (flag == 0)		//ó������ ������
			instance[i] = 1000;
	}

	for (int i = 0; i < K; i++) {
		for (int q = 0; q < useconcent; q++) {
			instance[concent[q][1]] -= 1;
		}
		if (useconcent == 0) {	//�ܼ�Ʈ�� �ϳ��� ���� ��
			concent[0][0] = list[i];	//��ȣ �Է�
			concent[0][1] = i;			//�ε��� �Է�
			useconcent++;		//��� �ܼ�Ʈ ����
		}
		else if(useconcent < N){		//�ܼ�Ʈ�� ������ ��
			int flag = 0;
			for (int j = 0; j < useconcent; j++) {	//������� �ܼ�Ʈ����
				if (list[i] == concent[j][0]) {		//���� ���������� Ȯ��
					concent[j][0] = list[i];
					concent[j][1] = i;
					flag = 1;
					break;
				}
			}
			if (flag == 0) {		//������ concent �߰�
				concent[useconcent][0] = list[i];
				concent[useconcent][1] = i;
				useconcent++;
			}
		}
		else {		//�ܼ�Ʈ�� �ȳ����� ��
			int flag1 = 0;
			for (int j = 0; j < N; j++) {	//���� ������ �ִ� Ȯ��
				if (list[i] == concent[j][0]) {
					concent[j][0] = list[i];
					concent[j][1] = i;
					flag1 = 1;
					break;
				}
			}
			//list index = instance index
			if (flag1 == 0) {	//�ܼ�Ʈ ������ ���
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