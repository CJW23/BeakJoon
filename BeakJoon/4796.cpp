#include <iostream>

using namespace std;
int L, P, V;
int div1, div2;
int Use;
int count1 = 1;
int main()
{

	while (1) { //L = 이용 가능일 P = 일 수중 V = 휴가 일 수
		cin >> L >> P >> V;
		if (L == 0 && P == 0 && V == 0)
			break;
		div1 = V / P;
		div2 = (V % P)/L;
		if (div2 > 0)
			Use = (div1*L) + L;
		else
			Use = (div1*L) + (V%P);
		cout <<"Case "<<count1<<": "<< Use << "\n";
		count1++;
	}
	return 0;
}