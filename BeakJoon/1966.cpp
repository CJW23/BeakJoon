#include <stdio.h>

int c;
int main()
{
	int a[10000];
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		bool confirm = false, endindex = false;
		int N, M, printNum = 0, index;
		int pri[101];

		int docnum;
		scanf("%d %d", &N, &M);		//N=���� �� M=���ϴ��ε���
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &pri[j]);
		}
		docnum = N;
		//////////////////////////�Է� �ܰ�
		while (!confirm) {
			if (docnum > 1) {
				for (int k = 1; k < docnum; k++) {
					int max = pri[0];
					if (max < pri[k]) {	//���� �켱������ ���� �ʴٸ�
						for (int m = 1; m < docnum; m++) {
							pri[m - 1] = pri[m];
						}
						pri[docnum - 1] = max;
						k = 0;
						if (M != 0)
							M--;
						else
							M = docnum - 1;

						pri[docnum - 1] = max;
						k = 0;
						continue;
					}
					if (k == docnum - 1) {			//////////??????
						if (M == 0) {		//���ϴ� �ε����� ��µɶ�
							printNum++;		//��� Ƚ�� ����
							confirm = true;
						}
						else {		//��� �ɋ�
							printNum++;		//���Ƚ�� ����
							for (int m = 1; m < docnum; m++)
								pri[m - 1] = pri[m];
							if (M != 0)
								M--;
							else
								M = docnum - 1;
							docnum--;
						}
					}
				}
			}
			else {
				confirm = true;
				printNum++;
			}

		}
		a[c] = printNum;
		c++;
	}
	for (int i = 0; i < c; i++)
	{
		printf("%d\n", a[i]);
	}
}