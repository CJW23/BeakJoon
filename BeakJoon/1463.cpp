//#INCLUDE <IOSTREAM>
//#INCLUDE <VECTOR>
//#INCLUDE <ALGORITHM>
//
//USING NAMESPACE STD;
//VECTOR<INT> COUNT1;
//
//INT F(INT X) {
//	INT RESULT;
//	IF (X == 1)
//		RETURN 0;
//	IF (COUNT1[X] != -1)
//		RETURN COUNT1[X];
//
//	RESULT = F(X - 1) + 1;
//	IF (X % 2 == 0)
//		RESULT = MIN(F(X / 2) + 1, RESULT);
//	IF (X % 3 == 0)
//		RESULT = MIN(F(X / 3) + 1, RESULT);
//
//	COUNT1[X] = RESULT;
//	RETURN RESULT;
//}
//
//INT MAIN() {
//	INT X;
//	INT Y;
//	CIN >> X;
//	COUNT1.RESIZE(X+1, -1);
//	Y = F(X);
//	COUT << Y;
//}
