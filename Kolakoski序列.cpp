//1

#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n, m;
	while (cin >> n >> m) {
		vector<int> ary(m, 0);
		for (int i = 0; i < m; i++) {
			cin >> ary[i];
		}
		vector<int> res;
		int end = 0;
		int begin = 0;
		for (int i = 0; i < m; i++) {
			if (ary[i] != 1) {
				for (int j = 0; j < ary[i]; j++) {
					res.push_back(ary[i]);
				}
				end = i + 1;   //m的起始下标
				begin = i + 1;   //res的起始下标
				break;
			}
			else {
				res.push_back(1);
			}
		}
		int num = res.size();
		while (num <= n) {
			end = end % m;
			int len = res[begin];
			for (int i = 0; i < len; i++) {
				res.push_back(ary[end]);
			}
			begin++;
			end++;
			num = res.size();
		}
		for (int i = 0; i < n; i++) {
			cout << res[i] << endl;
		}
	}
	return 0;
}
