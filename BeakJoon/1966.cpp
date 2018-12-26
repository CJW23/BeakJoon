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
		scanf("%d %d", &N, &M);		//N=문서 수 M=원하는인덱스
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &pri[j]);
		}
		docnum = N;
		//////////////////////////입력 단계
		while (!confirm) {
			if (docnum > 1) {
				for (int k = 1; k < docnum; k++) {
					int max = pri[0];
					if (max < pri[k]) {	//가장 우선순위가 높지 않다면
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
						if (M == 0) {		//원하는 인덱스가 출력될때
							printNum++;		//출력 횟수 증가
							confirm = true;
						}
						else {		//출력 될떄
							printNum++;		//출력횟수 증가
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