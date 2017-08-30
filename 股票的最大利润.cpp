#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int MaxDiff(vector<int> ary, int len) {
	int min = ary[0];
	int maxdiff = ary[1] - min;

	for (int i = 2; i < len; i++) {
		if (ary[i - 1] < min)
			min = ary[i - 1];
		if (ary[i] - min > maxdiff)
			maxdiff = ary[i] - min;
	}
	return maxdiff;
}

int main() {
	vector<int> ary = { 9,11,8,5,7,12,16,14 };
	cout << MaxDiff(ary, ary.size());
	system("pause");
	return 0;
}
