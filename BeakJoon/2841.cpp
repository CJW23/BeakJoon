#include <iostream>
#include <queue>
using namespace std;

typedef struct a {
	int jul;
	int pret;
}A;
int main()
{
	int N, P;
	int finger = 0;
	queue<A> a;
	queue<int> store[7];

	A temp;
	cin >> N >> P;

	for (int i = 0; i < N; i++) {
		cin >> temp.jul >> temp.pret;
		a.push(temp);
	}

	A tmp;
	for (int i = 0; i < N; i++) {
		tmp = a.front();
		a.pop();

		if (store[tmp.jul].empty()) {
			finger++;
			store[tmp.jul].push(tmp.pret);
		}
		else {		//tmp.pret
			int size = store[tmp.jul].size();
			bool same = false;
			while (size > 0)
			{
				if (store[tmp.jul].front() > tmp.pret) {
					store[tmp.jul].pop();
					finger++;
				}
				else if (store[tmp.jul].front() == tmp.pret) {
					same = true;
					store[tmp.jul].push(store[tmp.jul].front());
					store[tmp.jul].pop();
				}
				else if (store[tmp.jul].front() < tmp.pret) {
					store[tmp.jul].push(store[tmp.jul].front());
					store[tmp.jul].pop();
				}
				size--;
			}
			if (same == false)
			{
				store[tmp.jul].push(tmp.pret);
				finger++;
			}
		}
	}

	cout << finger;

}