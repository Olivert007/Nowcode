#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(int a, int b) {
	return a < b;
}

bool isContinues(vector<int> numbers,int len) {
	sort(numbers.begin(), numbers.end(), compare);
	int numZero = 0;
	int numGap = 0;
	for (int i = 0; i < len; i++) {
		if (numbers[i] == 0) {
			numZero++;
		}
	}
	int small = numZero;
	int big = small + 1;
	bool res=true;
	while (big < len) {
		if (numbers[small] == numbers[big]) {
			res = false;
		}
		numGap += numbers[big] - numbers[small] - 1;
		small = big;
		big++;
	}
	if (numGap > numZero)
		res = false;
	return res;
}

int main() {
	vector<int> numbers = { 0,2,4,5,6 };
	if (isContinues(numbers,numbers.size()))
		cout << "yes" << endl;
	else
		cout << "no" << endl;

	system("pause");
	return 0;
}
