#include<iostream>
#include<vector>
using namespace std;

int Sum(int x, int y) {
	int res = 0;
	for (int i = x; i <= y; i++) {
		res += i;
	}
	return res;
}

void PrintS(int x, int y) {
	for (int i = x; i < y; i++)
		cout << i << ", ";
	cout << y << endl;
}

void FindAry(int s) {
	int small = 1;
	int big = 2;
	
	while (small < big) {
		if (Sum(small, big) < s) {
			big++;
			continue;
		}
		if (Sum(small, big) > s) {
			small++;
			continue;
		}
		if (Sum(small, big) == s) {
			PrintS(small, big);
			big++;
		}
	}

}

int main() {
	int s = 15;
	
	FindAry(s);
	system("pause");
	return 0;
}
