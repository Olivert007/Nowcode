#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int *add(int a, int b) {//指针函数，返回类型是指针
	int* p=new int;
	//int* p = (int*)malloc(sizeof(int));//也可
	*p = a + b;
	return p;
}

int max(int a, int b) {
	return a > b ? a : b;
}
int min(int a, int b) {
	return a < b ? a : b;
}

int main() {
	int a = 1, b = 2;
	int* sum = add(a, b);
	cout << (*sum) << endl;

	int(*f)(int, int);//函数指针，函数名是指针
	f = min;
	int res_min = f(a, b);
	cout << res_min << endl;

	f = max;
	int res_max = f(a, b);
	cout << res_max << endl;

	delete[] sum;
	system("pause");
	return 0;
}
