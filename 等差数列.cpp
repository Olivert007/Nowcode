//https://www.nowcoder.com/question/next?pid=6291726&qid=112723&tid=9915152
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
//3 4 1 5 2 6
void QuickSort(vector<int>& s, int left, int right) {
	if (left < right) {
		int i = left, j = right, x = s[left];
		while (i < j) {
			while (s[j] > x)
				j--;
			if (i < j)
				s[i++] = s[j];
			while (i < j && s[i] < x)
				i++;
			if (i < j)
				s[j--] = s[i];
		}
		s[i] = x;
		QuickSort(s, left, i-1);
		QuickSort(s, i + 1, right);
	}
}

int main() {
	int n;
	cin >> n;
	if (n == 1) {
		cout << "Possible";
		return 0;
	}

	vector<int> x(n);
	for (auto &c : x)
		cin >> c;
	QuickSort(x, 0, x.size() - 1);

	int d = x[1] - x[0];
	for (int i = 0; i < x.size() - 1; i++) {
		if ((x[i + 1] - x[i]) != d) {
			cout << "Impossible";
			return 0;
		}
	}
	cout << "Possible";
	system("pause");
	return 0;
}
