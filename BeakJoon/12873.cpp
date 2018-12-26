//#include <iostream>
//#include <queue>
//using namespace std;
//
//int main()
//{
//	queue<int> data;
//	int num;
//	long long level = 1;
//	long long move;
//	long long realmove;
//	cin >> num;
//	for (int i = 1; i <= num; i++)
//		data.push(i);
//	
//	while (data.size() > 1) {
//
//		move = (level*level*level)-1;
//		
//		realmove = (long long)(move % data.size());
//		
//		
//		if (realmove >= 0)
//		{
//			for (long long i = 0; i < realmove; i++)
//			{
//				int temp = data.front();
//				data.pop();
//				data.push(temp);
//			}
//		}
//		else
//		{
//			int temp = data.front();
//			data.pop();
//			data.push(temp);
//		}
//		
//		data.pop();
//		level++;
//	}
//	cout << data.front();
//}