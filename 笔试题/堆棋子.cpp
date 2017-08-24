//https://www.nowcoder.com/question/next?pid=6291726&qid=112727&tid=9893427
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

void BubbleSort(vector<int>& ary) {
	for (int i = 0; i < ary.size(); i++) {
		for (int j = ary.size() - 1; j > i; j--) {
			if (ary[j] < ary[j - 1])
				swap(ary[j], ary[j - 1]);
		}
	}
}

int FindMiddle(vector<int> coor) {
	//BubbleSort(coor);
	sort(coor.begin(), coor.end(), less<int>());
	int length = coor.size();
	if (length % 2 == 0)
		return coor[length / 2 - 1];
	else
		return coor[length / 2];
}

int GotoMiddle(vector<int> xcoor, vector<int>ycoor, int x_dst, int y_dst, int n) {
	int sum=0;
	for (int i = 0; i < n; i++) {
		sum += abs(xcoor[i] - x_dst) + abs(ycoor[i] - y_dst);
	}
	return sum;
}

int main() {
	int n;
	cin >> n;
	vector<int> xcoor(n);
	for (auto &c : xcoor)
		cin >> c;
	vector<int> ycoor(n);
	for (auto &c : ycoor)
		cin >> c;

	int xmid, ymid;
	vector<int> xcoor_tmp, ycoor_tmp;
	vector<int> res;
	for (int i = 0; i < n; i++) {
		xcoor_tmp.push_back(xcoor[i]);
		ycoor_tmp.push_back(ycoor[i]);
		xmid = FindMiddle(xcoor_tmp);
		ymid = FindMiddle(ycoor_tmp);
		res.push_back(GotoMiddle(xcoor_tmp, ycoor_tmp, xmid, ymid, i+1));
	}

	for (int i = 0; i < n-1; i++) {
		cout << res[i] << " ";
	}
	cout << res[n - 1];

	system("pause");
	return 0;
}
