#include<iostream>
using namespace std;

int Add(int num1, int num2) {

	int sum,carry;
	do {
		sum = num1^num2;
		carry = (num1&num2) << 1;
		num1 = sum;
		num2 = carry;
	} while (carry != 0);
	return num1;
}

int main() {
	int num1 = 2;
	int num2 = 3;
	cout << Add(num1, num2) << endl;
	system("pause");
	return 0;
}
