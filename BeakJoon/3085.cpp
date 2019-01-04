//#include <iostream>
//#include <string.h>
//using namespace std;
//
//char pan[52][52];
//int main() {
//	int num;
//	char temp;
//	int best = 1;
//	int count = 1;
//	int flag = 1;
//	cin >> num;
//	for (int i = 0; i < num; i++){
//		for (int j = 0; j < num; j++) {
//			cin >> pan[i][j];
//		}
//	}
//	for (int i = 0; i < num-1; i++) {
//		for (int j = 0; j < num-1; j++) {
//			if (pan[i][j] != pan[i][j+1]) {
//				flag = 0;
//				break;
//			}
//			if (j == num - 2) {
//				if (pan[i][j + 1] != pan[i + 1][0]) {
//					flag = 0;
//					break;
//				}
//			}
//		}
//		if (flag == 0)
//			break;
//	}
//
//	if (flag == 1) {
//		for (int k = 0; k < num; k++) {
//			for (int z = 0; z < num; z++) {
//				if (z != num - 1) {
//					if (pan[k][z] == pan[k][z + 1]) {
//						count++;
//					}
//					else
//						count = 1;
//					if (count > best) {
//						best = count;
//					}
//				}
//			}
//			count = 1;
//			for (int z = 0; z < num; z++) {
//				if (z != num - 1) {
//					if (pan[z][k] == pan[z + 1][k]) {
//						count++;
//					}
//					else
//						count = 1;
//					if (count > best) {
//						best = count;
//					}
//				}
//			}
//			count = 1;
//		}
//	}
//	else {
//		for (int i = 0; i < num; i++)
//		{
//			for (int j = 0; j < num; j++)
//			{
//				count = 1;
//				///////가로 방향/////////
//				if (j!=num-1 && pan[i][j] != pan[i][j + 1])
//				{
//					/////////SWAP/////////
//					temp = pan[i][j];
//					pan[i][j] = pan[i][j + 1];
//					pan[i][j + 1] = temp;
//					///////////////////////
//
//					//////////////비교/////////////
//					for (int k = 0; k < num; k++) {
//						for (int z = 0; z < num; z++) {
//							if (z!=num-1 && pan[k][z] == pan[k][z + 1]) {
//								count++;
//							}
//							else
//								count = 1;
//							if (count > best) {
//								best = count;
//							}
//						}
//						count = 1;
//						for (int z = 0; z < num; z++) {
//							if (z!=num-1 && pan[z][k] == pan[z + 1][k]) {
//								count++;
//							}
//							else
//								count = 1;
//							if (count > best) {
//								best = count;
//							}
//						}
//						count = 1;
//					}
//					temp = pan[i][j];
//					pan[i][j] = pan[i][j + 1];
//					pan[i][j + 1] = temp;
//				}
//				//////세로 방향//////////
//				if (i!=num-1 && pan[i][j] != pan[i + 1][j]) {
//					temp = pan[i][j];
//					pan[i][j] = pan[i + 1][j];
//					pan[i + 1][j] = temp;
//					for (int k = 0; k < num - 1; k++) {
//						for (int z = 0; z < num - 1; z++) {
//							if (z!=num-1 && pan[k][z] == pan[k][z + 1]) {
//								count++;
//							}
//							else
//								count = 1;
//							if (count > best) {
//								best = count;
//							}
//						}
//						count = 1;
//						for (int z = 0; z < num - 1; z++) {
//							if (z!=num-1 && pan[z][k] == pan[z + 1][k]) {
//								count++;
//							}
//							else
//								count = 1;
//							if (count > best) {
//								best = count;
//							}
//						}
//						count = 1;
//					}
//					temp = pan[i][j];
//					pan[i][j] = pan[i + 1][j];
//					pan[i + 1][j] = temp;
//				}
//			}
//		}
//	}
//
//	cout << best;
//}
//
